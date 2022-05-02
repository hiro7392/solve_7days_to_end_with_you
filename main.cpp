#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
#define stringPair pair<string,string>
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0




// 文字cをnum文字ずらす
char rotateChar(char c,int num){
    int initPos=c-'a';
    int lastPos=initPos+num;
    while(lastPos<0){lastPos+=25;}
    while(lastPos>=26){lastPos-=26;}
    return 'a'+lastPos;
}

// encode後の文字列sと正しい答えの文字列trueStrから
// 何文字rotateしたか返す
int getNumber(string s,string trueStr){
    int ret=-1;
    for(int i=0;i<26;i++){
        int trueNum=0;
        rep(k,s.size()){
            if(rotateChar(s[k],i)!=trueStr[k]){
                trueNum=-1;
                break;
            }
            trueNum=i;
        }
        if(trueNum>=0){
            ret=trueNum;
            break;
        }
    }
    for(int i=-25;i<=0;i++){
        int trueNum=0;
        rep(k,s.size()){
            if(rotateChar(s[k],i)!=trueStr[k]){
                trueNum=1;
                break;
            }
            trueNum=i;
        }
        if(trueNum<0){
            ret=trueNum;
            break;
        }
    }
    return ret;
}

// 文字列sをrotateNumだけずらした文字列を得る
string getOriginEng(string s,int rotateNum){
    string ret;
    rep(i,s.size())ret.push_back(rotateChar(s[i],rotateNum));

    return ret;
}

//  入力用
pair<string,string>input(){
    string s,trueStr;
    printf("原文の暗号を入れてください: ");
    cin>>s;

    printf("英語の答えを入れてください: ");
    cin>>trueStr;
    return make_pair(s,trueStr);
}

//適当に暗号原文を入れてシーザー数0~25で逆変換する
void testSumNum(string s){

    for(int i=-26;i<=0;i++){
        cout<<"シーザ数 = "<<abs(i)<<" "<<getOriginEng(s,i)<<endl;
    }
    return;
}
void confirm(){
    stringPair strs=input();
    int rotateNumber=getNumber(strs.first,strs.second);
    cout<<"シーザー数は　"<<rotateNumber<<endl;   //23
    cout<<getOriginEng(strs.first,rotateNumber)<<endl;
}

//  入れた文字列を0〜25ずらしたものを表示
//  単語として成立するものがあればそれが元の単語だとわかる
void solve(){
    string s;
    printf("原文の暗号を入れてください: ");
    cin>>s;
    testSumNum(s);
    return ;
}
int main(){
    
    solve();
    //confirm();

}
/*


*/
