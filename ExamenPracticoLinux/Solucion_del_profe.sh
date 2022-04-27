#!/usr/bin/bash

#Paso 1
if [[ $UID -eq 0 ]]; then
   echo "Ejecutando filtrado de equipos por medio de mac-address" 
else
   echo "Este script solo puede ejecutarse como root"
   exit 1
fi

#Paso 2
if [[ $# -ne 2 ]]; then
   echo "Debe pasar dos argumento al script"
   exit 1
fi

#Paso 3
REGISTRO=$1
echo "El archivo de registros es $REGISTRO"
SALIDA=$2
echo "El archivo de salida con las direcciones mac-address es $SALIDA"

#Paso 4
touch $SALIDA
chmod a+r $SALIDA

#Paso 5
DHCPOFFERS='./ofrecimientosDHCP.txt'
echo "El archivo con los ofrecimientos de DHCP es $DHCPOFFERS"
cat $REGISTRO | grep "DHCPOFFER" > $DHCPOFFERS
chmod a+rw $DHCPOFFERS

#Paso 6
echo "Revisando conexiones indebidas..."

#Una forma
grep -E '\ 0[0-5]:[0-5][0-9]:[0-5][0-9]\ ' ofrecimientosDHCP.txt > indebidas1.txt #Esta revisa de medianoche hasta las 6am
grep -E '\ 2[2-3]:[0-5][0-9]:[0-5][0-9]\ ' ofrecimientosDHCP.txt >> indebidas1.txt #Esta revisa de las 10pm a medianoche
grep -E '192.168.13.[0-254]' indebidas1.txt > indebidas.txt #Esta filtra por IP
grep -o -E '[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}' indebidas.txt > $SALIDA #Coincidencia con mac-address
chmod a+wr $SALIDA
#Limpiar archivos intermedios
rm indebidas1.txt indebidas.txt

#Otra forma
while read LINEA; do 
    if [[ $LINEA == *2[2-3]:[0-5][0-9]:[0-5][0-9]*DHCPOFFER*192.168.13.[0-254]* ]] ||
       [[ $LINEA == *0[0-5]:[0-5][0-9]:[0-5][0-9]*DHCPOFFER*192.168.13.[0-254]* ]]; then
#    if [[ $LINEA == *0[0-5]:[0-5][0-9]:[0-5][0-9]*DHCPOFFER*192.168.13.[0-254]* ]]; then

      echo "$LINEA" | grep -o -E '([0-9a-f]{2}[:-]){5}([0-9a-f]{2})' >> salida2.txt
    fi
done < $REGISTRO
chmod a+wr salida2.txt

#y otra forma mas....
declare -a macs
count=0
while read line; do 
    if [[ $line == *DHCPREQUEST* ]]; then
      hora=${line:7:2}
      if [[ "10#$hora" -ge "0" && "10#$hora" -le "6" ]]; then #Horas de restriccion
        mac=`expr "$line" : '.*\([0-9a-f][0-9a-f]:[0-9a-f][0-9a-f]:[0-9a-f][0-9a-f]:[0-9a-f][0-9a-f]:[0-9a-f][0-9a-f]:[0-9a-f][0-9a-f]\)'`
        macs[$count]=$mac
        count=$(($count+1))
      fi
    fi
done < $REGISTRO

for mac in "${macs[@]}"; do
if [ "`grep -l $mac $SALIDA 2>/dev/null`" != "$SALIDA" ]; then #Verifica si el archivo de salida ya tiene la mac
  echo $mac>>output
fi
done

