interface ComputerWeight {
    public double computeWeight();
}
class Television implements ComputerWeight {
   ������1�� //��дcomputeWeight()����
}
class Computer implements ComputerWeight {
   ������2�� //��дcomputeWeight()����
}  
class WashMachine implements ComputerWeight {
   ������3�� //��дcomputeWeight()����
}
class Truck {
   ComputerWeight [] goods;
   double totalWeights=0;
   Truck(ComputerWeight[] goods) {
       this.goods=goods;
   }
   public void setGoods(ComputerWeight[] goods) {
       this.goods=goods;
   }
   public double getTotalWeights() {
      totalWeights=0;
     ������4�� //����totalWeights
      return totalWeights;
   }    
}
public class CheckCarWeight {
   public static void main(String args[]) {
      ComputerWeight[] goods=new ComputerWeight[650]; //650������
      for(int i=0;i<goods.length;i++) { //�򵥷ֳ�����
           if(i%3==0)
             goods[i]=new Television();
           else if(i%3==1)
             goods[i]=new Computer();
           else if(i%3==2)
             goods[i]=new WashMachine();
     } 
     Truck truck=new Truck(goods);
     System.out.printf("\n����װ�صĻ�������:%-8.5f kg\n",truck.getTotalWeights());
     goods=new ComputerWeight[68]; //68������
     for(int i=0;i<goods.length;i++) { //�򵥷ֳ�����
          if(i%2==0)
            goods[i]=new Television();
          else 
            goods[i]=new WashMachine();
     } 
     truck.setGoods(goods);
     System.out.printf("����װ�صĻ�������:%-8.5f kg\n",truck.getTotalWeights());
   }
}
