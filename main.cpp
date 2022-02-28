#include <iostream>
#include<math.h>


//Moisuc Rebeca-iulia, 1333B

using namespace std;

//zona de var globale si tipuri de var

typedef struct numar{
    int v;
    numar *urm;
}numar;

typedef struct numar2{
    int v;
    numar2 *urm;
    numar2 *prec;
}numar2;

typedef struct lista2
{
    numar2 *prim;//primul element din lista dublu inlantuita
    numar2 *ultim;//ultimul element din lista dublu inlantuita
}lista2;//tipul de variabila pentru coada

//zona pt functii

//rezolvare ecuatii
void rez_ec2(float a, float b, float c)
{
    float d, Pr, Pi, x1,x2;
    if(a!=0){
        d=b*b-4*a*c;
       if(d>=0)
       {
           x1=(-b+sqrt(d)/(2*a));
           x2=(-b-sqrt(d)/(2*a));
           cout<<"rad sunt reale diferite"<<endl;
           cout<<"x1= "<<x1<<endl;
           cout<<"x2= "<<x2<<endl;

       }
       else if(d==0)
       {
           cout<<"rad sunt reale si egale"<<endl;
           x1=-b/(2*a);
           cout<<"x1=x2= "<<x1<<endl;
       }
       else // d negativ
       {
           Pr=-b/(2*a);
           Pi=sqrt(-d)/(2*a);
           cout<<"rad complexe conjugate"<<endl;
           cout<<"x1= "<<Pr<<"+i*"<<Pi<<endl;
           cout<<"x2= "<<Pr<<"-i*"<<Pi<<endl;

       }}

else
 {
     cout<<" ec este de gr 1 si are ";
     if(b!=0)
     {
         x1=-c/b;
         cout<<"solutia "<<x1<<endl;
     }
     else
     {
         if(c!=0)
         {
             cout<<"nu are nicio sol"<<endl;
         }
         else {cout<<"are o inf de solutii"<<endl;}
     }
 }

}
void inmultire_matrice(int m,int n,int p,int r,float A[10][10], float B[10][10])
{
  if(n!=p)
    cout<<"inmultirea matricelor nu se poate"<<endl;
  else
  {
  float C[10][10]={0};
  for(int i=0;i<=m-1;i++)
    for(int j=0;j<=r-1;j++)
     {
      C[i][j]=0;
      for(int k=0;k<=n-1;k++)
        C[i][j]=C[i][j]+A[i][k]*B[k][j];
     }
   cout<<"produsul matricelor A si B"<<endl;

   for(int i=0;i<=m-1;i++)
    { for(int j=0;j<=n-1; j++)
       cout<<A[i][j]<<" ";
    cout<<endl;
    }

    cout<<" si "<<endl;

    for(int i=0;i<=n-1;i++)
    { for(int j=0;j<=r-1; j++)
       cout<<B[i][j]<<" ";
    cout<<endl;
    }
    cout<<" este"<<endl;
    for(int i=0;i<=m-1;i++)
    { for(int j=0;j<=r-1; j++)
       cout<<C[i][j]<<" ";
    cout<<endl;
    }
  }
}

bool test_nr_prim(int nr){
    if(nr < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(nr); i++){
        if(nr % 2 == 0){
            return false;
        }else{
        return true;
        }
    }
}

void nr_prime(int nr_prim){
    int prim;
    cout<<" Numerele prime mai mici sau egale cu "<<nr_prim<<" sunt: "<<endl;
    for(int i = 2; i <= nr_prim; i++){
        prim = 1;
        for(int j = 2; j <= i/2; j++)
            if(i % j == 0)
                prim = 0;
            if(prim == 1)
            cout<<i<<" "<<endl;
    }
}

void schimb_baza(int nr, int baza) {
    int nr_nou = 0;
    int p = 1;
    while(nr != 0){
        nr_nou = nr_nou + p * (nr_nou % baza);
        p  *= 10;
        nr /= baza;
    }
 cout<<endl<<" Numarul in baza "<<baza<<" este: "<<nr_nou<<endl;
}

//BubbleSort ordoneaa elementele vectorului prin interschimbarea elementelor care nu sunt
// in ordine crescatoare prin repetare.

void BubbleSort(int n, float x[50])
{
    float aux = 0;
    cout<<" Sirul neordonat este: ";
    for ( int i = 0; i < n; i++)
        cout<<x[i]<<" ";
        cout<<endl;

        //accesez fiecare element din sir
   for (int i = 0; i < n; i++) {
        //compar elementele sirului
      for (int j = i + 1; j < n; j++){

             if (x[i] > x[j])
          {
               aux = x[i];
               x[i] = x[j];
               x[j] = aux;
          }
      }
   }
   cout<<endl;
   cout<<" Sirul ordonat este: ";
   for ( int i = 0; i < n; i++)
    cout<<x[i]<<" ";
    cout<<endl;
}

//Selection Sort se bazeaza pe alegerea minimului din subsiruri ale sirului dat
// si asezarea pe pozitia corecta a acestui minim

void SelectionSort(int n, float x [50])
{
    int poz = 0, minim = 0;

    cout<<" Sirul neordonat este: ";
    for ( int i = 0; i < n; i++)
        cout<<x[i]<<" ";
        cout<<endl;

    for (int i = 0; i <= n - 2; i++){
       minim = x[i];
       poz = i;
       for (int j = i + 1; j <= n - 1; j++){
        if (minim > x[j]){
            minim = x[j];
            poz = j;
        }
        if(poz != i){
        int aux = x[i];
        x[i] = x[poz];
        x[poz] = aux;
        }
      }
    }
    cout<<endl;
    cout<<"Sirul ordonat este: ";
        for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
        cout<<endl;
}

//Algoritm de sortare prin numarare
void CountingSort (int n, float x[50])
{

    int maxim[50] ={0};
    float y[50];

    cout<<" Sirul neordonat este: ";
    for ( int i = 0; i < n; i++)
        cout<<x[i]<<" ";
        cout<<endl;


        for (int i = 0; i <= n - 2; i++){
            for (int j = i + 1; j <= n - 1; j++){
                if(x[i] <= x[j]){
                    maxim[j]++;
                }else{
                maxim[i]++;
                }
            }
        }
        cout<<endl;
        cout<<" Vectorul pozitiilor in sirul ordonat este: ";{
        for (int i = 0; i < n; i++){
            cout<<maxim[i]<<" ";
            y[maxim[i]] = x[i];
        }
        cout<<endl;
        cout<<endl;
        cout<<" Sirul ordonat esste: ";{
        for(int i = 0; i < n; i++)
            cout<<y[i]<<" ";
            cout<<endl;
        }
    }
}


//Algorimul este recursiv -> necesita scrierea intr-o functie recursiva
//se imparte sirul in 2 parti, se ordoneaza fiecare parte in acelasi mod

void Interclasare(int st, int mij, int dr, float x[50])
{
    float y[50];
    int i = st;
    int j = mij + 1;
    int k = 0; //indice pt y

    while ((i <= mij) && (j <= dr)){
        if(x[i] <= x[j])
        {
          y[k] = x[i];
          k++;
          i++;
        }else
        {
            y[k] = x[j];
            k++;
            j++;
        }
      }
      if(i <= mij)
      {
        for (int a = i; a <= mij; a++)
        {
            y[k] = x[a];
            k++;
        }
      }
      if(j <= dr)
      {
          for (int a = j; a <= dr; a++ )
          {
              y[k] = x[a];
              k++;
          }
      }
      for (int a = 0; a <= k - 1; a++)
      {
          x[st + a] = y[a];
      }
    }


void MergeSort(int stanga, int dreapta, float x[50])
{
    if (stanga < dreapta)
        {
        int m = (stanga + dreapta) / 2;
    MergeSort(stanga, m, x);
    MergeSort(m + 1, dreapta, x);
    Interclasare(stanga, m, dreapta, x);
    }
}


void QuickSort(int stanga, int dreapta, float x[50])
{
    if(stanga < dreapta)
    {
        float pivot = x[(stanga + dreapta) / 2];
        int i = stanga;
        int j = dreapta;
        while(i < j)
        {
            while((x[i] < pivot) && (i <= dreapta))
            {
                i++;
            }
            while((x[j] >= pivot) && (j >= stanga))
            {
                j--;
            }
            while (i < j)
            {
                int aux = x[i];
                x[i] = x[j];
                x[j] = aux;
                i++;
                j--;
            }
        }
        QuickSort(stanga, i, x);
        QuickSort(i + 2, dreapta, x);
    }
}

void InsertionSort(int n, float x[50])
{
    for (int i = 1; i <= n - 1; i++)
    {
        int aux = x[i];
        int j = i - 1;
        while((x[j] > aux)  && (j >= 0))
            {
            x[j+1]=x[j];
            j--;
        }
         x[j+1]=aux;
     }
        cout<<"Sirul ordonat este: ";
            for(int j=0;j<n;j++)
        cout<<x[j]<<" ";
        cout<<endl;
    }

void ShellSort(int n, float x[50])
{
    int pas = n / 2;

    cout<<" Sirul neordonat este: ";
    for ( int i = 0; i < n; i++)
        cout<<x[i]<<" ";
        cout<<endl;

    while (pas >= 1)
    {
        int i = 0;
        while ((i + pas) <= (n - 1))
          {
           int j = i;
           int aux = x[i + pas];
        while ((x[j] > aux) && (j >= 0))
        {
            x[j + pas] = x[j];
            j = j - pas;
        }
        x[j + pas] = aux;
        i++;
        }
         pas = pas / 2;
    }

     cout<<endl;

     cout<<" Sirul ordonat este: ";
            for(int j=0;j<n;j++)
        cout<<x[j]<<" ";
        cout<<endl;
}

void RadixSort(int n, float x[50])
{
    int maxi = 0;
    int y[50];
    for (int i = 1; i < n; i++)
    {
        if(x[i] > maxi)
            maxi = x[i];
    }
    cout<<" Cel mai mare numar din sir este: "<<maxi;
    cout<<endl;
    int M = 0; //nr maxim de cifre al nr din sir
    while (maxi != 0)
    {
        M++;
        maxi /= 10;
    }
    cout<<" Cel mai mare nr de cifre este: "<<M<<endl;
    int C[50][50] = {0};
    for (int i = 0; i <= n - 1; i++)
    {
        //creeaza matricea cifrelor nr din sir
        for(int j = 0; j <= M - 1; j++)
        y[j] = 0;
        //y e sirul cifrelor din x[i]
        int aux = x[i];
        int M1= 0;
        while (aux != 0)
        {
            y[M1] = aux % 10;
            aux = aux /10;
            M1++;
        }
               for(int j=0;j<=M1-1;j++)
       C[i][M-1-j]=y[j];//linia i din C scrie cifrele lui x[i], aliniate la dreapta

     }
     //scrie matricea C
     cout<<" Matricea cifrelor este:"<<endl;
     for(int i=0;i<=n-1;i++)
     {
         for (int j=0;j<=M-1;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
     }

     for(int j=M-1;j>=0;j--)
//sorteaza clasele de cifre de la clasa unitatilor
//corespunzatoare numerelor din x
     {  int i=0;
        for(int k=0;k<=9;k++)
         {
           for(int s=i;s<=n-1;s++)
              {
                if(C[s][j]==k)
                 {
                   for(int r=0;r<=M-1;r++)
                      y[r]=C[s][r];
// translateza liniile de la i pana la s-1
                   for(int p=s-1;p>=i;p--)
                      for(int r=0;r<=M-1;r++)
                         C[p+1][r]=C[p][r];
                   for (int r=0;r<=M-1;r++)
                      C[i][r]=y[r];
                   i++;
                 }
              }
         }

       cout<<"j= "<<j<<" i= "<<i<<endl;
       cout<<" Matricea  ordonata dupa coloana de cifre "<<j<<" este: "<<endl;
       for(int i1=0;i1<=n-1;i1++)
       {
         for (int j1=0;j1<=M-1;j1++)
            cout<<C[i1][j1]<<" ";
         cout<<endl<<endl;
       }
     }
//scrie din nou matricea C, cu numerele ordonate descompuse in cifre
     cout<<" Matricea ordonata este:"<<endl;
     for(int i=0;i<=n-1;i++)
     {
         for (int j=0;j<=M-1;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
     }
//recompunem numerele din matricea de cifre
     int i=0;
     while(i<=n-1)
     {
         y[i]=C[i][0];
         for(int j=1;j<=M-1;j++)
            y[i]=y[i]*10+C[i][j];
         i++;
     }
     cout<<" Sirul ordonat este: ";
       for(int j=0;j<n;j++)
    cout<<y[j]<<" ";
    cout<<endl;

}

void CautareSecventiala(int n, float x[50])
{
    float y;
    cout<<"Elementul de gasit este: ";
    cin>>y;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(x[i] == y)
        {
            cnt++;
        }
    }
    if(cnt == 0)
    {
        cout<<" Y nu se afla in sirul x.";
    }else
    {
        cout<<" Y se afla de "<<cnt<<" ori in sirul x.";
    }
}

void CautareBinara(int stanga, int dreapta, float x[50], float y)
{

    if(stanga < dreapta){

        int m = (stanga + dreapta) / 2;

        if(y == x[m])
        {
            cout<<" Y se afla in sirul x pe pozitia "<<m<<endl;

        }else
        if(y < x[m])
        {
           if(stanga <= m -1)
           {
               CautareBinara(stanga, m-1, x, y);
           }else
           {
               CautareBinara(m+1, dreapta, x, y);
           }
        }
    }
    else
    {
        if(y == x[stanga])
        {
            cout<<" Y se afla in sir pe pozitia "<<stanga<<endl;
        }else
        {
            cout<<" Y nu se afla in sir."<<endl;
        }
    }
  }

//functii pt liste simplu inlntuite
//*********************************
  numar *creare_lista()
{
    int x,n;
    numar *cap, *u, *c; // cap= element din capat lista , u= ultimul element din lista , c= element curent
    char a;
    //creaza lista si intoarce adresa primului element
    //scrie primul element din lista
    cout<< " Valoarea primul element din lista x= ";
    cin>>x;
    cap= new numar;
    cap->v=x;
    cap->urm=NULL;
    u=cap;
    //Adaugam elemente in lista
    n=0;
    do
    {
        cout<<"Adaugam elemente in lista [D][N]? ";
        cin>>a;
        if(a=='d' || a=='D')
        {
            cout<<"Valoarea x= ";
            cin>>x;
            c=new numar;
            c->v=x;
            c->urm=NULL;
            u->urm=c;
            u=c;
            n++;
        }
    }
    while (a=='d' || a=='D');
    cout<<endl;
    cout<<"Am adaugat "<<n<<" elemente in lista"<<endl;
    return cap;
}

 void parcurgere_lista(numar *cap)
{
    numar *c;//variabila curenta
    //Parcurge si afiseaza lista
    if(cap == NULL)
        cout<<"Lista este vida"<<endl;
    else
    {
        //cout<<"Lista este : ";
        for (c=cap; c!=NULL ; c=c->urm)
            cout<<c->v<<" " ;
        cout<<endl;
    }
}

  numar *adaugare_in_lista(numar *cap, int x)
{
    int ad,y;
    numar *p, *c, *u;
    //Adaugarea se poate face :
    //1 -- La inceput de lista ;
    //2 -- In lista, dupa un element y din lista , daca exista
    //3 -- Dupa ultimul element din lista

    do
    {
        cout<<endl<<"Adaugarea se poate face :"<<endl;
        cout<<"1 - La inceput de lista ;"<<endl;
        cout<<"2 - In lista, dupa un element y din lista , daca exista;" <<endl;
        cout<<"3 - Dupa ultimul element din lista"<<endl;
        cout<<"Alege tip de adaugare: ";
        cin>>ad;
        cout<<endl;

        if(ad==1)// adauga inainte de capatul listei
        {
            p=new numar;
            p->v=x;
            p->urm=cap;
            cap=p;
            cout<<"Lista dupa adaugare inainte de capat este: ";
            parcurgere_lista(cap);

        }
        if(ad==2)// adauga dupa element din lista
        {
            cout<<"Citesc elementrul dupa care adaugam :";
            cin>>y;
            cout<<endl;
            c=cap;
            while (c!= NULL)
            {
                if(c->v==y )
                {
                    //adauga x dupa y
                    if(c->urm ==NULL) // c este ultimul element
                    {
                        p=new numar;
                        p->v=x;
                        p->urm=NULL;
                        c->urm=p;
                        c=c->urm;


                    }
                    else //c este in interiorul listei, nu este ultimul element al listei
                    {
                        p=new numar;
                        p->v=x;
                        p->urm=c->urm;
                        c->urm=p;
                        c=c->urm;

                    }
                }
                c=c->urm;
            }
            cout<<"Lista dupa adaugare dupa elementul y din lista: ";
            parcurgere_lista(cap);

        }
        if(ad==3)// adauga dupa ultimul element din lista
        {
            u=cap;
            while (u->urm != NULL)
                u=u->urm;
            p=new numar;
            p->v=x;
            p->urm=NULL;
            u->urm=p;
            cout<<"Lista dupa adaugare dupa ultimul element din lista: ";
            parcurgere_lista(cap);
        }
    }
    while (ad==1 || ad==2 || ad==3);
    return cap;
}

numar * sterg_in_lista(numar * cap, int b)
{
    int nr=0; // b- elementul de sters , nr - nr de elemente sterse
    numar *c,*p;
    if(cap==NULL)
        cout<<"vida ";
    else
    {
        while (cap!=NULL )//sterge elementele care au valoare b din capatul listei , daca exista
        {
            if (cap->v==b)
            {
                cap=cap->urm;
                nr++;
            }
            else
                break;
        }
        if(cap!=NULL)
        {
            c=cap->urm;
            p=cap;//p este precedentul elementului curent din lista
            while(c!=NULL)
            {
                if(c->v==b)//c contine valoare b si va fi sters din lista
                {
                    p->urm=c->urm;
                    nr++;
                    c=c->urm;
                }
                else
                {
                    p=c;
                    c=c->urm;
                }
            }
        }

        cout<<"Valoarea "<<b<<" a fost stearsa de "<<nr<<" ori."<<endl;
    }
    return cap;
}

numar *modificare_lista(numar * cap,int x,int y)
{
    numar *c;
    for(c=cap; c!=NULL; c=c->urm)
    {
        if(c->v==x)
            c->v=y;
    }
    return cap;
}



//functia principala
void lista_simplu_inlantuita()
{
    numar * cap_lista;
    int a;//element de adaugat
    int b;//element de sters
    int m;//element ajutator
    int x,y;
    // apeluri catre functiile pentru liste simplu inlantuite
    //crearea listei
    cap_lista=creare_lista();
    cout<<endl;
    cout<<"Lista dupa creare este : ";
    parcurgere_lista(cap_lista);
    cout<<endl;
    do
    {
        cout<<"1 - Adaugare element "<<endl;
        cout<<"2 - Stergere element" <<endl;
        cout<<"3 - Modificare element"<<endl;
        cout<<"Aleg: ";
        cin>>m;
        cout<<endl;
        if(m==1)
        {
            //adaugare in lista
            cout<<"Adaugare in lista a = ";
            cin>>a;
            cap_lista=adaugare_in_lista(cap_lista,a);
            cout<<"Lista dupa ADAUGARE este : ";
            parcurgere_lista(cap_lista);
            cout<<endl;
        }
        if(m==2)
        {
            //stergere din lista
            cout<<"Sterg din lista elementul b=";
            cin>>b;
            cap_lista=sterg_in_lista(cap_lista,b);
            cout<<"Lista dupa STERGERE este: ";
            parcurgere_lista(cap_lista);
            cout<<endl;
        }

        if(m==3)
        {
            //modificare in lista
            cout<<"Valoare de modificat: ";
            cin>>x;
            cout<<endl;
            cout<<"Se inlocuieste cu valoarea: " ;
            cin>>y;
            cap_lista=modificare_lista(cap_lista,x,y);
            cout<<"Lista dupa modificare este: ";
            parcurgere_lista(cap_lista);
            cout<<endl;
        }

    }
    while (m==1||m==2||m==3);
}
//Functii pt liste dublu inlantuite
//*****************************************

lista2 *creare_lista2()
{
    int x,n;

    lista2 *cap;
    numar2  *p, *u, *c; // p= prim element din lista ,
    // u= ultimul element din lista , c= element curent
    char a;
    //creaza lista si intoarce element de tip lista2 (adica, prim si ultim element de tip numar2
    //scrie primul element din lista2
    cout<< " Valoarea primul element din lista x= ";
    cin>>x;
    p=new numar2;
    u=new numar2;
    p->v=x;
    p->urm=NULL;
    p->prec=NULL;
    u=p;

    cap=new lista2;
    cap->prim=p;
    cap->ultim=u;

    //Adaugam elemente in lista
    n=1;
    do
    {
        cout<<"Adaugam elemente in lista [D][N]? ";
        cin>>a;
        if(a=='d' || a=='D')
        {
            cout<<"Valoarea x= ";
            cin>>x;
            c=new numar2;
            c->v=x;
            c->urm=NULL;
            c->prec=u;
            u->urm=c;
            u=c;
            n++;
        }
    }
    while (a=='d' || a=='D');
    cout<<endl;
    cout<<"Am adaugat "<<n<<" elemente in lista"<<endl;
    cap->ultim=u;
    return cap;
}

void parcurgere_directa(lista2 *L)
{
    numar2 *c;
    // parcurge si afiseaza lista incepand cu primul element
    if (L->prim == NULL)
        cout<<"Lista este vida!"<<endl;
    else
    {
        //cout<<"Lista este: ";
        for(c=L->prim; c !=NULL; c=c->urm)
            cout<<c->v<<" ";
        cout<<endl;
    }
}


void parcurgere_inversa(lista2 *L)
{
    numar2 *c;
    // parcurge si afiseaza lista incepand cu ultimul element
    if (L->ultim == NULL)
        cout<<"Lista este vida!"<<endl;
    else
    {
        //cout<<"Lista este: ";
        for(c=L->ultim; c !=NULL; c=c->prec)
            cout<<c->v<<" ";
        cout<<endl;
    }
}

lista2 *adaugare_in_lista2(lista2 *L, int x)
{
    int ad,y;
    numar2 *p, *c;
    //Adaugarea se poate face :
    //1 -- La inceput de lista ;
    //2 -- In lista, dupa un element y din lista , daca exista
    //3 -- Dupa ultimul element din lista

    do
    {
        cout<<endl<<"Adaugarea se poate face :"<<endl;
        cout<<"1 - La inceput de lista ;"<<endl;
        cout<<"2 - In lista, dupa un element y din lista , daca exista;" <<endl;
        cout<<"3 - Dupa ultimul element din lista"<<endl;
        cout<<"Alege tip de adaugare: ";
        cin>>ad;
        cout<<endl;

        if(ad==1)// adauga inainte de capatul listei
        {
            p=new numar2;
            p->v=x;
            p->urm=L->prim ;
            p->prec=NULL;
            (L->prim)->prec=p;
            L->prim=p;
            cout<<"Lista dupa adaugare inainte de capat este: ";
            parcurgere_directa(L);

        }
        if(ad==2)// adauga dupa element din lista
        {
            cout<<"Citesc elementrul dupa care adaugam :";
            cin>>y;
            cout<<endl;
            c=L->prim;
            while (c!= NULL)
            {
                if(c->v==y )
                {
                    //adauga x dupa y
                    if(c->urm ==NULL) // c este ultimul element
                    {
                        p=new numar2;
                        p->v=x;
                        p->urm=NULL;
                        p->prec=L->ultim;
                        (L->ultim)->urm=p;
                        L->ultim=p;
                        c->urm=p;
                        c=c->urm;


                    }
                    else //c este in interiorul listei, nu este ultimul element al listei
                    {
                        p=new numar2;
                        p->v=x;
                        p->urm=c->urm;
                        p->prec=c;
                        (c->urm)->prec=p;
                        c->urm=p;
                        c=c->urm;

                    }
                }
                c=c->urm;
            }
            cout<<"Lista dupa adaugare dupa elementul y din lista: ";
            parcurgere_directa(L);

        }
        if(ad==3)// adauga dupa ultimul element din lista
        {
            p=new numar2;
            p->v=x;
            p->urm=NULL;
            p->prec=L->ultim;
            (L->ultim)->urm=p;
            L->ultim=p;
            cout<<"Lista dupa adaugare dupa ultimul element din lista: ";
            parcurgere_directa(L);
        }
    }
    while (ad==1 || ad==2 || ad==3);
    return L;
}


lista2 * sterg_in_lista2(lista2 *L, int b)
{
    int nr=0; // b- elementul de sters , nr - nr de elemente sterse
    numar2 *c;
    if(L==NULL)
        cout<<"Nimic de sters. Lista este vida. ";
    else
    {
        while (L->prim!=NULL )//sterge elementele care au valoare b din capatul listei , daca exista
        {
            if (L->prim->v==b)
            {
                if((L->prim)->urm!=NULL)
                {
                    ((L->prim)->urm)->prec=NULL;
                    L->prim=(L->prim)->urm;
                    nr++;
                }
                else
                    //a sters ultimul element din lista
                {
                    L->ultim=NULL;
                    L->prim=NULL;
                    nr++;
                }

            }
            else
                break;
        }
        cout<<"Dupa stergere in capatul listei:";
        parcurgere_directa(L);

        if(L->prim!=NULL)
        {
            c=(L->prim)->urm;
            //p=c;//p este precedentul elementului curent din lista
            while(c!=NULL)
            {
                if(c->v==b)//c contine valoare b si va fi sters din lista
                {
                    if(c->urm!=NULL)//c nu este ultimul element
                    {
                        (c->prec)->urm=c->urm;
                        (c->urm)->prec=c->prec;
                        nr++;
                        c=c->urm;
                        cout<<"A sters 1 data:";
                        parcurgere_directa(L);
                    }
                    else
                        //c este ultimul element din lista
                    {
                        (c->prec)->urm=NULL;
                        L->ultim=c->prec;
                        c=c->urm;
                        nr++;
                        cout<<"A sters ultim element";
                        parcurgere_directa(L);
                    }
                }
                else
                {
                    c=c->urm;
                }
            }
        }

        cout<<"Valoarea "<<b<<" a fost stearsa de "<<nr<<" ori."<<endl;
        cout<<"Lista a ramas:";
        parcurgere_directa(L);

    }
    return L;
}

lista2 *modificare_lista2(lista2 *L, int x, int b)
{
     numar2 *c;
    for(c = L -> prim; c!=NULL; c=c->urm)
    {
        if(c->v == x)
            c->v = b;
    }
    return L;
}

void lista_dublu_inlantuita()
{
    lista2 *L;//capetele listei
    int m,x,b;
    L=creare_lista2();
    cout<<"Lista incepand cu primul element este: ";
    parcurgere_directa(L);
    cout<<"Lista incepand cu ultimul element este: ";
    parcurgere_inversa(L);

    do
    {
        cout<<"1 - Adaugare element "<<endl;
        cout<<"2 - Stergere element" <<endl;
        cout<<"3 - Modificare element"<<endl;
        cout<<"Aleg: ";
        cin>>m;
        cout<<endl;
        if(m==1)
        {
            cout<<"Se adauga in lista valoarea x=";
            cin>>x;
            L=adaugare_in_lista2(L,x); //adaugare in lista
            cout<<"Lista dupa adaugare incepand cu primul element este: ";
            parcurgere_directa(L);
            cout<<"Lista dupa adaugare incepand cu ultimul element este: ";
            parcurgere_inversa(L);
        }
        if(m==2)
        {
            cout<<"Se sterge in lista valoarea b=";
            cin>>b;
            L=sterg_in_lista2(L,b); //sterg in lista
            cout<<"Lista dupa stergere incepand cu primul element este: ";
            parcurgere_directa(L);
            cout<<"Lista dupa stergere incepand cu ultimul element este: ";
            parcurgere_inversa(L);//stergere din lista

        }

        if(m==3)
        {
            //modificare in lista
            cout<<" Elementul care se modifica x= ";
            cin>>x;
            cout<<" Primeste valoarea b = ";
            cin>>b;
            L= modificare_lista2(L, x, b);
            cout<<" Lista directa dupa modificare este: ";
            parcurgere_directa(L);
            cout<<" Lista inversa dupa moodificare este: ";
            parcurgere_inversa(L);

        }

    }
    while (m==1||m==2||m==3);
}

//Functii pentru stive
//--------------------------------------------------

  numar *creare_stiva()



{
    int x,n;
    numar *cap, *c; // cap= element din capat lista , u= ultimul element din lista , c= element curent
    char a;
    //creaza lista si intoarce adresa primului element
    //scrie primul element din lista
    cout<< " Valoarea primul element din lista x= ";
    cin>>x;
    cap= new numar;
    cap->v=x;
    cap->urm=NULL;

    //Adaugam elemente in lista
    n=1;
    do
    {
        cout<<"Adaugam elemente in stiva [D][N]? ";
        cin>>a;
        if(a=='d' || a=='D')
        {
            cout<<"Valoarea x= ";
            cin>>x;
            c=new numar;
            c->v=x;
            c->urm=cap;
            cap = c;
            n++;
        }
    }
    while (a=='d' || a=='D');
    cout<<endl;
    cout<<"Am adaugat "<<n<<" elemente in stiva"<<endl;
    return cap;
}

 void parcurgere_stiva(numar *cap)
{
    numar *c;//variabila curenta
    //Parcurge si afiseaza stiva
    if(cap == NULL)
        cout<<"Lista este vida"<<endl;
    else
    {
        //cout<<"Lista este : ";
        for (c=cap; c!=NULL ; c=c->urm)
            cout<<c->v<<endl;
        cout<<endl;
    }
}

numar *adaugare_stiva(numar *S, int x)
{
    numar *a;
    //adaugare in stiva existenta
    a = new numar;
    a -> v = x;
    a -> urm = S;
    S = a;
    return S;
}

numar *stergere_stiva(numar *S)
{
    if(S != NULL)

    S = S ->urm;

    return S;
}

void stive()
{
    numar *S;
    int m;
    int x;
    do
    {
        cout<<" 1. Creare stiva "<<endl;
        cout<<" 2. Adaugare stiva "<<endl;
        cout<<" 3. Stergere stiva "<<endl;
        cout<<" Alege optiune: ";
        cin>>m;
        if(m == 1)
        {
            S = creare_stiva();
            cout<<" Stiva creata este: "<<endl;
            parcurgere_stiva(S);

        }
        if(m == 2)
            //adaugam element in stiva
        {
            cout<<" Se adauga in stiva elementul: ";
            cin>>x;
            S = adaugare_stiva(S, x);
            cout<<" Stiva dupa adaugare este: "<<endl;
            parcurgere_stiva(S);
        }
        if(m == 3)
            //stergem element din stiva
        {
            S = stergere_stiva(S);
            cout<<" Stiva dupa stergere este: "<<endl;
            parcurgere_stiva(S);
        }
    }
    while(m == 1 || m == 2 || m == 3);

}

//Functii pentru cozi
//----------------------------

lista2 *creare_coada()
{
    int x,n;

    lista2 *C;
    numar2  *p, *u, *c; // p= prim element din coada ,
    // u= ultimul element din coada , c= element curent
    char a;
    //creaza coada si intoarce element de tip lista2 (adica, prim si ultim element de tip numar2
    //scrie primul element din lista2
    cout<< " Valoarea primul element din coada x= ";
    cin>>x;
    p=new numar2;
    u=new numar2;
    p->v=x;
    p->urm=NULL;
    p->prec=NULL;
    u=p;

    C=new lista2;
    C->prim=p;
    C->ultim=u;

    //Adaugam elemente in coada
    n=1;
    do
    {
        cout<<"Adaugam elemente in coada [D][N]? ";
        cin>>a;
        if(a=='d' || a=='D')
        {
            cout<<"Valoarea x= ";
            cin>>x;
            c=new numar2;
            c->v=x;
            c->urm=NULL;
            c->prec=u;
            u->urm=c;
            u=c;
            n++;
        }
    }
    while (a=='d' || a=='D');
    cout<<endl;
    cout<<"Am adaugat "<<n<<" elemente in lista"<<endl;
    C->ultim=u;
    return C;
}


void parcurgere_coada_direct(lista2 *L)
{
    numar2 *c;
    // parcurge si afiseaza coada incepand cu primul element
    if (L->prim == NULL)
        cout<<" Coada este vida!"<<endl;
    else
    {

        for(c=L->prim; c !=NULL; c=c->urm)
            cout<<c->v<<" ";
        cout<<endl;
    }
}


void parcurgere_coada_invers(lista2 *L)
{
    numar2 *c;
    // parcurge si afiseaza coada incepand cu ultimul element
    if (L->ultim == NULL)
        cout<<" Coada este vida!"<<endl;
    else
    {

        for(c=L->ultim; c !=NULL; c=c->prec)
            cout<<c->v<<" ";
        cout<<endl;
    }
}

lista2 *adaugare_coada(lista2 *L, int x)
{
    numar2 *c;
    c = new numar2;
    c -> v = x;
    c -> urm = NULL;
    c -> prec = L -> ultim;
    (L -> ultim) -> urm = c;
    L -> ultim = c;
    return L;
}

lista2 *stergere_coada(lista2 *L)
{
    if((L -> prim)!= NULL)
    {
         if(((L -> prim) -> urm) != NULL)
          {
             ((L -> prim) -> urm) -> prec = NULL;

          }else
              {
               L -> ultim = NULL;
              }

        L -> prim = (L -> prim) -> urm;

    }else
    {
        cout<<" Nu mai e nimeni la coada."<<endl;
    }
    return L;
}

void cozi()
{
    lista2 *C;
    int m;
    int x;
    do
    {
        cout<<" 1. Creare coada "<<endl;
        cout<<" 2. Adaugare la coada "<<endl;
        cout<<" 3. Stergere coada "<<endl;
        cout<<" Alege optiune: ";
        cin>>m;
        if(m == 1)
        {
            C = creare_coada();
            cout<<" Coada parcursa direct este: "<<endl;
            parcurgere_coada_direct(C);
            cout<<" Coada parcursa invers este: "<<endl;
            parcurgere_coada_invers(C);
        }
        if(m == 2)
            //adaugam element la coada
        {
            cout<<" Se adauga la coada elementul: ";
            cin>>x;
            C = adaugare_coada(C, x);
            cout<<" Coada dupa adaugare parcursa direct este: "<<endl;
            parcurgere_coada_direct(C);
            cout<<" Coada dupa adaugare parcursa invers este: "<<endl;
            parcurgere_coada_invers(C);
        }
        if(m == 3)
            //stergem element din coada
        {
            C = stergere_coada(C);
            cout<<" Coada  dupa stergere parcursa direct este: "<<endl;
            parcurgere_coada_direct(C);
            cout<<" Coada  dupa stergere parcursa invers este: "<<endl;
             parcurgere_coada_invers(C);
        }
    }
    while(m == 1 || m == 2 || m == 3);

}

int main()
{ int optiune;//program principal
  int op1;//optiune cap 1
  int op2; //optiune cap 2
  int op3; //optiune cap 3
  int op4; //optiune cap 4
    do{
         cout<<endl<<"Program ASD - Moisuc Rebeca-Iulia, subgrupa 1333B"<<endl<<endl;
         cout<<"1.Probleme simple rezolvate in C++"<<endl;
         cout<<"2.Algoritmi de sortare"<<endl;
         cout<<"3. Liste dinamice. Aplicatii"<<endl;

         cout<<"0.Incheiere program"<<endl;
         cout<<endl<<"Optiune meniu principal: "; cin>>optiune;

    switch (optiune){
    case 1:
        do{
        cout<<endl<<" Probleme simple rezolvate in C++"<<endl;
        cout<<"    1. Rezolvare completa ec de gr 2"<<endl;
        cout<<"    2. Matrice"<<endl;
        cout<<"    3. Nr prim"<<endl;
        cout<<"    4. Afisare nr prime"<<endl;
        cout<<"    5. Schimbare baza"<<endl;
        cout<<"   1.0 Iesire"<<endl;
        cout<<" Optiune capitol 1: "; cin>>op1;
          switch(op1){
      case 1:
       float a1,b1,c1;
       cout<<" Coef. ec. a1*x^2+b1*x+c1=0 sunt:"<<endl;
       cout<<" a1= "; cin>>a1;
       cout<<" b1= "; cin>>b1;
       cout<<" c1= "; cin>>c1;
       rez_ec2(a1,b1,c1);

        break;
      case 2:
          int n,m,p,r;
          float A1[10][10], B1[10][10];

          cout<<" Dimensiuni matrice A1: "; cin>>m;cin>>n;
          cout<<" Dimensiuni matrice B1: "; cin>>p;cin>>r;
          cout<<" Matricea A1 este: "<<endl;
          for(int i=0;i<=m-1;i++)
             { for(int j=0;j<=n-1; j++)
               cin>>A1[i][j];

             }
         cout<<" Matricea B1 este: "<<endl;
          for(int i=0;i<=p-1;i++)
             { for(int j=0;j<=r-1; j++)
               cin>>B1[i][j];

             }
          inmultire_matrice(m,n,p,r,A1,B1);
        break;

      case 3:
          int nr_prim;
          cin>>nr_prim;
           if(test_nr_prim(nr_prim) == true){
            cout<<" Numarul este prim."<<endl;
           }else{
            cout<<" Numarul nu este prim."<<endl;
           }
           break;

      case 4:
        int numar_prim;
        cin>>numar_prim;
        nr_prime(numar_prim);
        break;


      case 5:
        int numar, b;
        cin>>numar;
        cin>>b;
        schimb_baza(numar, b);
        break;
      case 0:
        cout<<" Incheiere cap 1. "<<endl;
        break;

      default:
          cout<<" Optiune cap 1 invalida. ";
        break;
        }

        }while(op1!=0);
        break;

    case 2:
         // algoritmi de sortare si cautare
          // citim sirul de ordonat
          int n;
          //float x[100];
          cout<<" Dimensiune sir n = "; cin>>n;
          float x[50];
          cout<<" Sirul de ordonat este: ";
          for(int i=0; i<n; i++)
            cin>>x[i];
          do{
              cout<<endl<<"2. Algoritmi de sortare si cautare"<<endl;
              cout<<"     2.1. Bubble Sort"<<endl;
              cout<<"     2.2. Selection Sort"<<endl;
              cout<<"     2.3. Counting Sort"<<endl;
              cout<<"     2.4. Merge Sort"<<endl;
              cout<<"     2.5. Quicksort"<<endl;
              cout<<"     2.6. Insertion Sort"<<endl;
              cout<<"     2.7. Shell Sort"<<endl;
              cout<<"     2.8. Radix Sort"<<endl;
              cout<<"     2.9. Cautare secventiala"<<endl;
              cout<<"     2.10. Cautare binara"<<endl;
              cout<<"     2.0. Iesire din capitol algoritmi de sortare"<<endl<<endl;

              cout<<"   Alege optiune capitol 2: "; cin>>op2;
              cout<<endl;

              switch (op2)
              {
              case 1:
                //algoritmul BubbleSort
                //copiem in y sir de sortat x
                float y[50];

                for ( int i = 0; i < n; i++)
                    y[i] = x[i];
                    BubbleSort(n,y);

                break;



              case 2: //Selection sort
                   float z[50];

                for ( int i = 0; i < n; i++)
                    z[i] = x[i];
                    SelectionSort(n,z);

              break;

                case 3: //Counting sort
                   float a[50];

                for ( int i = 0; i < n; i++)
                    a[i] = x[i];
                    CountingSort(n,a);

              break;

                case 4:
                //algoritmul MerggeSort
                cout<<" Sirul neordonat este: ";
                for(int i = 0; i < n; i++)
                {
                    y[i] = x[i];
                    cout<<y[i]<<" ";
                }
                cout<<endl;
                MergeSort(0, n-1, y);
                cout<<" Sirul ordonat este: ";
                for(int i = 0; i< n; i++)
                {
                    cout<<y[i]<<" ";
                }
                 cout<<endl;
                break;

                case 5:
                    //algortimul QuickSort
                    cout<<" Sirul neordonat este: ";
                for(int i=0;i<n;i++)
                {
                    y[i]=x[i];
                    cout<<y[i]<<" ";
                }
                cout<<endl;
                QuickSort(0, n-1, y);

                 cout<<" Sirul ordonat este: ";
                 for(int j = 0; j <= n-1; j++)
                  cout<<y[j]<<" ";
                  cout<<endl;
                break;

               case 6:
                   //algoritmul InsertionSort
                cout<<" Sirul neordonat este: ";
                for(int i = 0; i < n; i++)
                {
                    y[i] = x[i];
                    cout<<y[i]<<" ";
                }
                cout<<endl;
                InsertionSort(n,y);
                break;

            case 7:
                //algoritmul ShellSort
                //copiem in b un sir de sortat x
                float b[50];

                for ( int i = 0; i < n; i++)
                    b[i] = x[i];
                    ShellSort(n,b);

                break;

            case 8:
                //algoritmul RadixSort
                //copiem in d sir de sortat x
                float d[50];

                for ( int i = 0; i < n; i++)
                    d[i] = x[i];
                    RadixSort(n,d);

                break;

             case 9:
                //Cautarre Secventiala
                float e[50];

                for ( int i = 0; i < n; i++)
                    e[i] = x[i];
                    CautareSecventiala(n,e);

                break;

             case 10:
                  float f;
                  cout<<" Elementul de cautat este:";
                  cin>>f;
               cout<<" Sirul este:";
                for(int i=0;i<n;i++)
                {
                    y[i]=x[i];
                    cout<<y[i]<<" ";
                }
                cout<<endl;
                MergeSort(0,n-1,y);
                 cout<<" Sirul ordonat este:";
                for(int i=0;i<n;i++)
                    cout<<y[i]<<" ";

                cout<<endl;
                CautareBinara(0,n-1,y,f);
                break;
 case 0:
        cout<<" Incheiere cap 1. "<<endl;
        break;

      default:
          cout<<" Optiune cap 1 invalida. ";
        break;
        }

        }while(op1!=0);
        break;

        case 3: // liste dinamice
            do
            {
                cout<<endl<<"3. Liste dinamice. Aplicatii"<<endl;
                cout<<"     3.1. Liste simplu inlantuite."<<endl;
                cout<<"     3.2. Liste dublu inlantuite."<<endl;
                cout<<"     3.3. Stive."<<endl;
                cout<<"     3.4. Cozi"<<endl;
                cout<<"     3.5. Creearea unei liste ordonata crescator. "<<endl;
                cout<<"     3.6. Interclasarea a doua liste ordonate crescator. "<<endl;
                cout<<"     3.7. Adunarea  polinoamelor cu ajutorul listelor.  "<<endl;
                cout<<"     3.8. Inmultirea polinoamelor cu ajutorul listelor.  "<<endl;
                cout<<"     3.9. Verificarea corectitudinii parantezelor intr-o expresie aritmetica."<<endl;
                cout<<"     3.0. Iesire din capitol liste dinamice"<<endl;

                cout<<"   Alege optiune capitol 3: ";
                cin>>op3;
                switch (op3)
            {
                case 1:
                    //liste simplu inlantuite
                    lista_simplu_inlantuita();
                    break;

                case 2:
                    //lioste dublu inlantuite
                    lista_dublu_inlantuita();
                    break;
                case 3:
                    //stive
                    stive();
                    break;
                case 4:
                    //cozi
                    cozi();
                    break;
                case 5:

                    break;

                case 6:

                    break;
                case 7:

                    break;
                case 8:
                    break;
                case 9:

                    break;
                 case 0:
                    cout<<" A inchis capitolul 3!"<<endl<<endl;
                    break;

                default:
                    cout<<endl<<"Optiune invalida!!!"<<endl<<endl;
                    break;

                }// end switch cap 3
            }
            while(op3!=0);
            break;

            case 4:
            do
            {
                cout<<endl<<"4. Grafuri"<<endl;
                cout<<"     4.1. Reprezentare matrice de adiacenta <=> lista de noduri."<<endl;
                cout<<"     4.2. Reprezentare matrice de adiacenta <=> lista de muchii."<<endl;
                cout<<"     4.3. Reprezentare lista de noduri <=> lista de muchii."<<endl;
                cout<<"     4.4. Moduri de parcurgere grafuri: in adancime si in latime."<<endl;
                cout<<"     4.5. Verificare existenta drum intre oricare doua noduri."<<endl;
                cout<<"     4.0. Iesire din capitol grafuri"<<endl;

                cout<<"   Alege optiune capitol 4: ";

                cin>>op4;
                switch (op4)
                {
                case 1:

                    break;

                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 0:
                    cout<<" A inchis capitolul 4!"<<endl<<endl;
                    break;

                default:
                    cout<<endl<<"Optiune invalida!!!"<<endl<<endl;
                    break;

                }// end switch cap 3
            }
            while(op4!=0);
            break;

    case 0:
        cout<<" La revedere!"<<endl;

    default:
        cout<<" Optiune invalida!"<<endl;
       break;

    }//end switch program principal
    }
    while(optiune!=0);


    return 0;
}
