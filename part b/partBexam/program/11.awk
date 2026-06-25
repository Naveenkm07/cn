BEGIN{
packet=0
packet1=0
time=0;
# Throughput=0
}
{
 if($1=="r"&&$4=="7"&&$5=="cbr")
{
 packet=packet+$6
 time=$2
packet1++
}
}
END{
 throughput=(packet*8)/(time*1000000);
 printf("\n total number of data packets at Node7:%d\n",packet1);
 printf("\n Throughput: %f Mbps\n", throughput);
}
