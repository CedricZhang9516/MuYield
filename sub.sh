#chmod +x /home/had/zhangce/MuYield/run.sh
#bsub /home/had/zhangce/MuYield/run.sh
: '
i=0

while [ "$i" != "200" ]
do

    i=$(($i+1))

    chmod +x /home/had/zhangce/MuYield/run_210205_SlineItvScan_9_$i.sh
    bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_9_$i.sh
done

'

#bsub /home/had/zhangce/MuYield/run_210205_Sline_0.sh
#bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_4_0.sh
#bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_5_0.sh
#bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_6_0.sh
#bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_7_0.sh
#bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_8_0.sh
#bsub /home/had/zhangce/MuYield/run_210205_SlineItvScan_9_0.sh