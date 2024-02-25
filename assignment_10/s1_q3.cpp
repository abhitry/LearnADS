 #include<iostream>
 using namespace std;
// class Node
// {
//     public:
//     int vertex;
//     Node*next;
//     Node()
//     {
//         vertex=0;
//         next=NULL;
//     }
//     Node(int a)
//     {
//         vertex=a;
//         next=NULL;
//     }
// };

// int main()
// {
//     int n;
//     cout<<"enter vertices= ";
//     cin>>n;
//     int wt;
//     cout<<"is it weighted= ";
//     cin>>wt;
//     bool dir;
//     cout<<"is it directed= ";
//     cin>>dir;
//     vector<Node*>vct;
//     for(int i=0;i<n;i++)
//     {
//         vct.push_back(NULL);
//     }
//     cout<<"enter edges= ";
//     int u,v;
//     while(1)
//     {
//         cin>>u>>v;
//         if(u==-1 || v==-1)
//         {
//             break;
//         }
//         //insert(u,v);
//         if(vct[u]==NULL)
//         {
//             vct[u]=new Node(v);
//         }
//         else{
//             Node*p=vct[u];
//             while(p->next!=NULL)
//             {
//                 p=p->next;
//             }
//             p->next=new Node(v);
//         }
//         //insert(v,u);
//         if(vct[v]==NULL)
//         {
//             vct[v]=new Node(u);
//         }
//         else{
//             Node*p=vct[v];
//             while(p->next!=NULL)
//             {
//                 p=p->next;
//             }
//             p->next=new Node(u);
//         }
//     }
//     Node*p=NULL;
//     for(int i=0;i<n;i++)
//     {
//         p=vct[i];
//         cout<<i<<"      ";
//         while(p!=NULL)
//         {
//             cout<<p->vertex<<" ";
//             p=p->next;
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int n;
//     cout<<"enter vertices= ";
//     cin>>n;
//     vector<vector<int> >adjlist(n);
//     vector<int >sublist;
//     int i;
//     for( i=0;i<n;i++)
//     {
//         adjlist.push_back(sublist);
//     }
//     int u,v;
//     cout<<"enter edges= ";
//     while(1)
//     {
//         cin>>u>>v;
//         if(u==-1 || v==-1)
//         {
//             break;
//         }
//         adjlist[u].push_back(v);
//         adjlist[v].push_back(u);
//     }
//     vector<vector<int> >::iterator itr;
//     vector<int>::iterator subitr;
//     for(itr=adjlist.begin();itr<adjlist.end();itr++)
//     {
//         for(subitr=(*itr).begin();subitr<(*itr).end();subitr++)
//         {
//             cout<<*subitr<<" ";
//         }
//         cout<<endl;
//     }
// }
int main()
{
    int n;
    cout<<"enter vertices= ";
    cin>>n;
    vector<int>vct[n];
    int i,j;
    int u,v;
    cout<<"enter edges-= ";
    while(1)
    {
        cin>>u>>v;
        if(u==-1 || v==-1)
        {
            break;
        }
        vct[u].push_back(v);
        vct[v].push_back(u);
    }
    vector<int>::iterator itr;
    for(i=0;i<n;i++)
    {
        itr=vct[i].begin();
        cout<<i<<"      ";
        while(itr!=vct[i].end())
        {
            cout<<*itr<<" ";
            itr++;
        }
        cout<<endl;
    }
}