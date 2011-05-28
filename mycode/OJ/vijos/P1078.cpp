#include <stdio.h>
int main(){
int i,j,n,m,guo[201],step,height=1,num;
scanf("%d%d",&n,&m);
for (i=1;i<=n;i++) guo[i]=i;
for (i=1;i<=m;i++){
step=i*i*i%5+1;
if (height+step<=n-i+1) height+=step;
else height=step+1;
num=guo[height];
for (j=height;j<=n-i;j++) guo[j]=guo[j+1];
}
printf("%d",num);
return 0;
} 

/*     From ken_carter 
松鼠吃果子　   
 描述 Description   
   　　 有N个一种松鼠喜欢吃的果子由下向上串排成一列，并标号1,2,...N。一只松鼠从最下果子开始向上跳
   ，并且第i次跳可以一次跳过i*i*i除以5的余数+1个果子(=i*i*i%5+1)，并把脚下的果子吃了，如果上面有果
   子，在重力作用下，都将向下掉下一格。如第1次跳从第一个果子上跳过1*1*1%5+1=2个果子，可跳到第3个果
   子上，并把第3个果子吃了；第2次从第4个果子上(落在原来第三个果子位置)跳过2*2*2%5+1=4个到第8个果子
   上，并把第8个吃了；如此...。
　　 当然，总有一次松鼠会跳出这串果子的最前面，设为每K次，它吃不到任何果子了。这时它回到最下面的果
子上，重做它的第K次跳，以求吃到果子。如此，问它吃的第m只果子(即第M跳吃到的果子)的标号是什么？ 
   
 输入格式 Input Format  
   一共两行，分别为N和m。（1<=m<=n<=200，并且满足能够跳到第m次）  
   
 输出格式 Output Format  
   一个数，即它吃的第m只果子的标号。 
   
 样例输入 Sample Input   
   10
4
 样例输出 Sample Output   
   9
 
 注释 Hint  
   注：吃掉的果子依次为3，8，5(回到下面重做第3跳)，9(回到下面重做第4跳) 
*/
