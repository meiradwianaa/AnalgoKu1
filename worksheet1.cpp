/*
Nama		: Meira Dwiana Anjani
NPM			: 140810180015
Kelas 		: A 
Deskripsi	: Stable Matching Problem 
*/

#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  

#define N 5 
  
// Fungsi true jika wanita lebih menyukai pria 'm1' daripada 'm'
bool pilihPria(int pilih[2*N][N], int w, int m, int m1) 
{ 
    //Cek wanita lebih suka m daripada m1 
    for (int i = 0; i < N; i++) 
    { 
        if (pilih[w][i] == m1) 
            return true; 
         
        if (pilih[w][i] == m) 
           return false; 
    } 
} 
  

void stableMarriage(int pilih[2*N][N]) 
{ 
    int wPartner[N]; 
  
    bool mFree[N]; 
  
    memset(wPartner, -1, sizeof(wPartner)); 
    memset(mFree, false, sizeof(mFree)); 
    int freeCount = N; 
  
    // Jika pria ada yang Free 
    while (freeCount > 0) 
    {  
        int m; 
        for (m = 0; m < N; m++) 
            if (mFree[m] == false) 
                break; 
  
        for (int i = 0; i < N && mFree[m] == false; i++) 
        { 
            int w = pilih[m][i]; 
  
            if (wPartner[w-N] == -1) 
            { 
                wPartner[w-N] = m; 
                mFree[m] = true; 
                freeCount--; 
            } 
  
            else  // Jika wanita tidak free 
            { 
                int m1 = wPartner[w-N]; 
  
                if (pilihPria(pilih, w, m, m1) == false) 
                { 
                    wPartner[w-N] = m; 
                    mFree[m] = true; 
                    mFree[m1] = false; 
                } 
            } 
        } 
    } 
  
  
    // Memunculkan Hasilnya
    cout << "Hasil Stable Matching : " << endl;
    cout << "--------------------------------"<< endl;
    cout << "Man \t\tWoman" << endl; 
    cout<<endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++) {
       if(i<N){
     if(wPartner[i]==0)
      man="Victor";
     if(wPartner[i]==1)
      man="Wyatt ";
     if(wPartner[i]==2)
      man="Xavier";
     if(wPartner[i]==3)
      man="Yancey";
     if(wPartner[i]==4)
      man="Zeus  ";
     if(i==0)
      woman="Amy";
     if(i==1)
      woman="Bertha";
     if(i==2)
      woman="Clare";
     if(i==3)
      woman="Diane";
     if(i==4)
      woman="Erika";
  }
  cout << man << "\tX\t" << woman << endl; 
 }   
} 
  
// Uji Main Program 
int main() 
{ 
   int pilih[2*N][N] = { {6, 5, 8, 9, 7}, 
        {8, 6, 5, 7, 9},
        {6, 9, 7, 8, 5},
        {5, 8, 7, 6, 9},
        {6, 8, 5, 9, 7},
        {4, 0, 1, 3, 2},
        {2, 1, 3, 0, 4},
        {1, 2, 3, 4, 0},
        {0, 4, 3, 2, 1},
        {3, 1, 4, 2, 0} 
    }; 
    stableMarriage(pilih); 
  
    return 0; 
}
