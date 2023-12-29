//
//  main.cpp
//  main
//
//  Created by Naman Goyal on 05/08/23.
//

#include <iostream>
#include <vector>
using namespace::std;
class SET{
private:
    vector<vector<int> >v;
    vector <int> size_v;
public:
    int binarysearch(vector<int>v,int n, int i, int l){
        
        int b = (l-i+1)/2;
        if (i ==l){
            if (v[i] == n){
                return i;
            }
            else {
                return -1;
            }
        }
        else if (l ==i+1){
            if (v[i] == n){
                return i;
            }
            else if (v[l] == n){
                return l;
            }
            else {
                return -1;
            }
        }
        else{
            if(v[b+i]>n){
                return binarysearch(v, n, i, b+i-1);
            }
            else if (v[b+i]==n){
                return b+i;
            }
            else{
                return binarysearch(v, n, b+i+1, l);
            }
            
        }
        
        
        
        
        
        
    }
    
    
    
    void create(int b){
        vector<int>m;
        
        v.push_back(m);
        size_v.push_back(0);
    }
    
    void insert(int b,int k ){
        
        
        vector<int>d;
        int n = size_v[b-1];
        int i =0;
        if (n==0){
            v[b-1].push_back(k);
            size_v[b-1]++;
            cout<<size_v[b-1]<<"\n";
        }
        else{int p=0;
            while(v[b-1][i]<=k && i<n){
                if (v[b-1][i]==k){
                    cout<<size_v[b-1]<<"\n";
                    p=1;
                    break;
                }
                else if (v[b-1][i]<k){
                    d.push_back(v[b-1][i]);
                    
                }
                
                i++;
            }
            if(i==n){
                d.push_back(k);
                size_v[b-1]++;
                cout<<size_v[b-1]<<"\n";
                v[b-1] = d;
            }
            if (v[b-1][i]!=k && i<n &&p==0){
                d.push_back(k);
                for (int j = i;j<n;j++){
                    d.push_back(v[b-1][j]);
                }
                size_v[b-1]++;
                cout<<size_v[b-1]<<"\n";
                v[b-1] = d;
            }
            
            
        }}
    void Delete(int b,int k){
        if (size_v[b-1]!=0){
            vector<int>d;
            
            int f = binarysearch(v[b-1], k, 0, size_v[b-1]-1);
            if (f == -1){
                cout<<size_v[b-1]<<"\n";
            }
            else{
                for(int i = 0;i<f;i++){
                    d.push_back(v[b-1][i]);
                }
                for(int i = f+1;i<size_v[b-1];i++){
                    d.push_back(v[b-1][i]);
                }
                v[b-1] = d;
                size_v[b-1]--;
                cout<<size_v[b-1]<<"\n";
                
            }
        }
        else{
            cout<<size_v[b-1]<<"\n";
        }
    }
    void belongto(int b, int k){
        if(size_v[b-1]!=0){
            int f = binarysearch(v[b-1], k, 0, size_v[b-1]-1);
            if(f == -1){
                cout<<0<<"\n";
            }
            else{
                cout<<1<<"\n";
            }
            
        }
        else{
            cout<<0<<"\n";
            
        }
    }
    void size(int b){
        cout<<size_v[b-1]<<"\n";
    }
    void print(int b){
        if(size_v[b-1]!=0){
            for (int i = 0;i<size_v[b-1];i++){
                cout<<v[b-1][i];
                if (i!=size_v[b-1]-1){
                    cout<<",";
                }
            }
            cout<<"\n";
        }
        else{
            cout<<"\n";
        }
    }
    void intersection(int b, int c){
        if(size_v[b-1]!=0&&size_v[c-1]!=0){
            vector<int>d;
            int k = 0;
            if (b!=c){
                if (size_v[b-1]>=size_v[c-1]){
                    int f = 0;
                    int fl = 0;
                    
                    
                    for (int i = 0;i<size_v[c-1];i++){
                        
                        
                        
                        f = binarysearch(v[b-1], v[c-1][i], f, size_v[b-1]-1);
                        
                        if(f!=-1){
                            d.push_back(v[b-1][f]);
                            fl = f;
                            k++;
                        }
                        if (f == -1){
                            f = fl;
                        }
                        
                    }
                    
                    
                }
                else{
                    int f = 0;
                    int fl = 0;
                    
                    for (int i = 0;i<size_v[b-1];i++){
                        
                        
                        
                        f = binarysearch(v[c-1], v[b-1][i], f, size_v[c-1]-1);
                        if (f!=-1){
                            
                            d.push_back(v[c-1][f]);
                            fl = f;
                            k++;
                        }
                        if (f == -1){
                            f = fl;
                        }
                        
                    }
                }
            }
            else{
                
                k = size_v[b-1];
                d = v[b-1];
            }
            v[b-1] = d;
            size_v[b-1] = k;
            cout<<k<<"\n";
            
        }
        else if (size_v[b-1]==0){
            cout<<0<<"\n";
        }
        else{
            v[b-1] = v[c-1];
            size_v[b-1] = 0;
            cout<<0<<"\n";
        }
    }
    void Union(int b, int c){
        if(size_v[b-1]!=0&&size_v[c-1]!=0){
            vector<int>d;
            int i=0, j = 0,k = 0;
            while (i<size_v[b-1]&&j<size_v[c-1]){
                if (v[b-1][i]<v[c-1][j]){
                    d.push_back(v[b-1][i]);
                    i++;
                    k++;
                }
                else if (v[b-1][i]==v[c-1][j]){
                    d.push_back(v[b-1][i]);
                    i++;
                    j++;
                    k++;
                }
                else {
                    d.push_back(v[c-1][j]);
                    j++;
                    k++;
                }
                
            }
            
                while(j<size_v[c-1]){
                    d.push_back(v[c-1][j]);
                    j++;
                    k++;
                }
            
                while(i<size_v[b-1]){
                    d.push_back(v[b-1][i]);
                    i++;
                    k++;
                
                
            }
            v[b-1] = d;
            size_v[b-1]=k;
            cout<<k<<"\n";
            
        }
        else if (size_v[b-1]==0){
            v[b-1] = v[c-1];
            size_v[b-1] = size_v[c-1];
            cout<<size_v[b-1]<<"\n";
            
        }
        else{
            cout<<size_v[b-1]<<"\n";
        }
    }
    void difference(int b, int c){
        if(size_v[b-1]!=0&&size_v[c-1]!=0&&b!=c){
            vector<int>d;
            
            int r = 0;
            for(int i= 0;i<size_v[b-1];i++){
                int l = 0;
                for(int j = 0;j<size_v[c-1];j++){
                    if(v[b-1][i]==v[c-1][j]){
                        l = 1;
                        break;
                    }
                    
                }
                if (l==0){
                    d.push_back(v[b-1][i]);
                    r++;
                    
                }
            }
            v[b-1] = d;
            size_v[b-1] = r;
            
            cout<<size_v[b-1]<<"\n";
            
        }
        else if (b==c){
            vector<int>d;
            size_v[b-1] = 0;
            v[b-1] = d;
            cout<<size_v[b-1]<<"\n";
        }
        
        else{
            cout<<size_v[b-1]<<"\n";
        }
    }
    void symdiff(int b, int c){
        if(size_v[b-1]!=0&&size_v[c-1]!=0){
            vector<int>d;
            int i=0, j = 0,k = 0;
            while (i<size_v[b-1]&&j<size_v[c-1]){
                if (v[b-1][i]<v[c-1][j]){
                    d.push_back(v[b-1][i]);
                    i++;
                    k++;
                }
                else if (v[b-1][i]==v[c-1][j]){
                    
                    i++;
                    j++;
                    
                }
                else {
                    d.push_back(v[c-1][j]);
                    j++;
                    k++;
                }
                
            }
            
                while(j<size_v[c-1]){
                    d.push_back(v[c-1][j]);
                    j++;
                    k++;
                }
            
                while(i<size_v[b-1]){
                    d.push_back(v[b-1][i]);
                    i++;
                    k++;
                }
            v[b-1] = d;
            size_v[b-1]=k;
            cout<<k<<"\n";
        }
        else if(size_v[b-1]==0){
            v[b-1] = v[c-1];
            size_v[b-1] = size_v[c-1];
            cout<<size_v[b-1]<<"\n";
            
        }
        else{
            cout<<size_v[b-1]<<"\n";
        }}
};
int main() {
    SET A;

    int LSN; //last set no.
    int a;

    
    LSN = 0;
    while(cin >> a){
        
        
        int b,c;
        cin>> b;
        b++;
        if (a!=6 && a!=9){
            cin>>c;
        }
       
       
            if (a == 1){
                if(LSN+1==b){
                    LSN++;
                    A.create(b);
                    
                    A.insert(b,c);
                }
                else{
                    A.insert(b,c);
                }
                
                
            }
            else if (a==2){
                if(b>LSN){
                    A.create(b);
                    LSN++;
                    
                    cout<<-1<<"\n";
                }
             
                else{
                    A.Delete(b,c);
                }
            }
            else if(a==3){
                if (b<=LSN){
                    A.belongto(b,c);}
                else{
                    cout<<-1<<"\n";
                }
            }
            else if(a==6){
                if (b>LSN){
                    A.create(b);
                    LSN++;
                    
                }
                A.size(b);
            }
            else if (a==9){
                if (b>LSN){
                    A.create(b);
                    LSN++;
                    
                }
                A.print(b);
            }
            else if (a == 5){
                c++;
                if (b<c){
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                        
                    }
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                        
                    }}
                if (b>c){
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                        
                    }
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                        
                    }}
                if(b==c&&b>LSN){
                    A.create(b);
                    LSN++;
                    
                }
                A.intersection(b,c);
            }
            else if (a==4){
                c++;
                if (b<c){
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                        
                    }
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                        
                    }}
                if (b>c){
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                        
                    }
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                        
                    }}
                if(b==c&&b>LSN){
                    A.create(b);
                    LSN++;
                    
                }
                
                A.Union(b, c);
            }
            else if (a==7){
                c++;
                if (b<c){
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                        
                    }
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                        
                    }}
                if (b>c){
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                        
                    }
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                        
                    }}
                if(b==c&&b>LSN){
                    A.create(b);
                    LSN++;
                
                }
                A.difference(b, c);
                
            }
            else if (a == 8){
                c++;
                if (b<c){
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                      
                    }
                    if (c>LSN){
                        A.create(c);
                        LSN++;
               
                    }}
                if (b>c){
                    if (c>LSN){
                        A.create(c);
                        LSN++;
                      
                    }
                    if (b>LSN){
                        A.create(b);
                        LSN++;
                    
                    }}
                if(b==c&&b>LSN){
                    A.create(b);
                    LSN++;
                
                }
                A.symdiff(b, c);
                
            }
            
          
        }}
    