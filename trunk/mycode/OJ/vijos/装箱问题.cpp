#include<cstdio>
main()
{
      int n,v,i,j,x,max=0;
      bool a[20001]={false};
      a[0]=true;
      scanf("%d",&v);
      scanf("%d",&n);
      for(i=0;i<n;i++){
                       scanf("%d",&x);
                       for(j=max;j>=0;j--){
                                           if(a[j]){
                                                    if(j+x<=v)
                                                    {a[j+x]=true;
                                                     if(j+x>max)max=j+x; 
                                                     }
                                                     }
                                           }
                       }
      printf("%d",v-max);
}
