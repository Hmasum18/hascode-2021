#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define repv(i, m) for (auto i = m.begin(); i != m.end(); i++)
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
//const long long INF = 40000000000000000LL;
/************************************* Trie Harder *************************************/
struct Street
{
    int id, u, v, w;
    string name;
    Street(int a, int bee, int cee, int d, string r)
    {
        id = a;
        u = bee;
        v = cee;
        w = d;
        name = r;
    }
    Street() {}
};
string path, filename;
int D, n, m, c, F;
map<string, int> index;
vector<Street> street;
vector<vector<int>> carsPath, outDegree, inDegree;
void ReadInputFile(string f)
{
    ifstream infile(f);
    string line;
    int i = 0;
    while (getline(infile, line))
    {
        istringstream iss(line);
        if (i == 0)
        {
            iss >> D >> n >> m >> c >> F;
            carsPath.resize(c);
        }
        else if (i <= m)
        {
            Street s;
            s.id = i - 1;
            iss >> s.u >> s.v >> s.name >> s.w;
            index[s.name] = i - 1;
            street.pb(s);
        }
        else
        {
            int p;
            iss >> p;
            while (p--)
            {
                string k;
                iss >> k;
                carsPath[i - m - 1].pb(index[k]);
            }
        }
        i++;
    }
    cout << D << " " << n << " " << m << " " << c << " " << F << endl;
    for (Street s : street)
    {
        cout << s.u << " " << s.v << " " << s.name << "->" << s.w << endl;
    }
    for (int j = 0; j < c; j++)
    {
        cout << carsPath[j].size();
        for (int g : carsPath[j])
        {
            cout << " " << g;
        }
        cout << endl;
    }
    cout << "OKAY" << endl;
}

void WriteOutputFile(string f)
{
    ofstream outfile(f + "_output.txt");
    outfile << n << endl;
    for (int i = 0; i < n; i++)
    {
        outfile << i << endl
                << inDegree[i].size() << endl;
        for (int j : inDegree[i])
        {
            outfile << street[j].name << " " << 1 << endl;
        }
    }
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << endl
             << inDegree[i].size() << endl;
        for (int j : inDegree[i])
        {
            cout << street[j].name << " " << 1 << endl;
        }
    }
}
void Initialization()
{
    outDegree.resize(n);
    inDegree.resize(n);

    for (Street s : street)
    {
        outDegree[s.u].pb(s.id);
        inDegree[s.v].pb(s.id);
    }
}
int main()
{
    path = "../input-files/";
        filename = "a";
    //    filename = "b";
    //    filename = "c";
    //filename = "d.txt";
    //    filename = "e";
    //filename = "f";

    ReadInputFile(path + filename+".txt");
    Initialization();

    path = "../output-files/";
    WriteOutputFile(path + filename);

    //    for(Street s:street){
    //        cout << s.name << endl;
    //    }
}