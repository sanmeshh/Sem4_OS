// Online C compiler to run C program online
#include <stdio.h>
void fcfs(int n,int p[],int at[],int bt[]){
    int temp;
    int avgwt=0,avgtat=0;
    int ct[5]={0,0,0,0,0},tat[5]={0,0,0,0,0},wt[5]={0,0,0,0,0};
    for(int i=0;i<n;i++){
        
       int pos=i;
       for(int j=i+1;j<n;j++){
           if(bt[pos]>bt[j]){
               pos=j;
           }
           
       }
       int temp;
       
       temp=bt[i];
       bt[i]=bt[pos];
       bt[pos]=temp;
       
       temp=p[i];
       p[i]=p[pos];
       p[pos]=temp;
    }
    temp=0;
    for(int i=0;i<n;i++){
        temp+=bt[i];
        if(at[i]>temp){
            ct[i]=at[i]+temp;
        }
        else{
            ct[i]=temp;
        }
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgtat+=tat[i];
        avgwt+=wt[i];
        
    }
    printf("\nPid\tBurst\tTurn\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i],  tat[i], wt[i]);
    }
    printf("gant chart:\n");
    printf("first%d\t", (wt[0] - at[0]));
    for (int i = 0; i < n; i++) {
        printf("%d\t", ct[i]);
    }
    
    printf("\nAverage waiting time: %f", avgwt/(float)n);
    printf("\nAverage turnaround time: %f", avgtat/(float)n);

}

int main() {
 int bt[]={6,8,7,3};
 int at[]={0,0,0,0,0};
 int p[]={1,2,3,4};
 fcfs(4,p,at,bt);
 
 
}
