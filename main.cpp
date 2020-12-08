#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
double cnt[9999][2];/// cnt[i][0]代表i题目做得总次数，cnt[i][1]代表题目i做错误的次数
const double c_puct=7;
int n;
int tot_vis=0;
double rd(){double  tem;scanf("%lf",&tem);return tem;}
void load(){
    cout<<"---------------------------------------------*0"<<endl;
    freopen("save.txt","r+",stdin);
    cout<<"---------------------------------------------*1"<<endl;

    scanf("%d",&n);
    cout<<"---------------------------------------------*2"<<endl;
    if(n==0){
        n=49;
        freopen("CON","r",stdin);
        return ;
    }
    for(int i=1;i<=n;++i){
        cnt[i][0]=rd();cnt[i][1]=rd();
        tot_vis+=cnt[i][0];
    }
    freopen("CON","r",stdin);
}
void save(){
    freopen("save.txt","w+",stdout);
    cout<<n<<endl;
    for(int i=1;i<=n;++i){
        cout<<cnt[i][0]<<' '<<cnt[i][1]<<endl;
    }
    fclose(stdout);
    freopen("CON","w",stdout);
}

int choose(){
    int id=1;
    double tem_val=0;
    for(int i=1;i<=n;i++){
        double val=0;
        if(cnt[i][0]==0){
            val=1;
        }else{
            val=(1-(1.0*cnt[i][1])/(1.0*cnt[i][0]));
        }

        val*=4;

        val+=c_puct*sqrt(1.0*tot_vis)/(1+1.0*cnt[i][0]);
        cout<<i<<' '<<val<<endl;
        if(val>tem_val){
            id=i;
            tem_val=val;
        }
    }
    return id;
}
void print_menu(){
    cout<<"Do you want to quit?"<<endl;
    cout<<"input your choose,quit:1  ,continue: 0"<<endl;
}
void update_cnt(int row,int val){
    if(val>0){
        val=1;
    }else{
        val=0;
    }
    ++tot_vis;
    ++cnt[row][0];
    cnt[row][1]+=val;
}
int main(){
    //cout<<"---------------------------------------------*1"<<endl;
    load();
    while(1){
        save();
        //cout<<"---------------------------------------------3"<<endl;
        int choose_id=choose();
        cout<<"YOU SHOULD SOLVE THE QUESTOIN ID:"<<choose_id<<endl;
        cout<<"Did you solve it?"<<endl;
        cout<<"yes?"<<endl;
        cout<<"input the result"<<endl;
        int tem;
        scanf("%d",&tem);
        update_cnt(choose_id,tem);
    }
}
