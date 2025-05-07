// Online C compiler to run C program online
#include <stdio.h>
void fcfs(int n,int p[],int at[],int bt[]){
    int temp=0;
    int avgwt=0,avgtat=0;
    int ct[5]={0,0,0,0,0},tat[5]={0,0,0,0,0},wt[5]={0,0,0,0,0};
    for(int i=0;i<n;i++){
        temp+=bt[i];
        if(at[i]>temp){
            ct[i]=at[i]+temp;
        }
        else{
            ct[i]+=temp;
        }
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
        
    }
    printf("\nPid\tArrival\tBurst\tComplete\tTurn\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("gant chart:\n");
    printf("first%d\t", (wt[0] - at[0]));
    for (int i = 0; i < n; i++) {
        printf("%d\t", ct[i]);
    }
    
    printf("\nAverage waiting time: %f", (avgwt / n));
    printf("\nAverage turnaround time: %f", (avgtat / n));

}

int main() {
 int bt[]={4,3,1,2,5};
 int at[]={0,1,2,3,4};
 int p[]={1,2,3,4,5};
 fcfs(5,p,at,bt);
 
 
}
