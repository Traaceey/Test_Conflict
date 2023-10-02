#include <iostream>
#include <cstring>

using namespace std;

class VE
{
protected:
    string Ma;
    string Ten;
    int Namsinh;
    int Sotrochoi;

public:
    VE(string = " ", string = " ", int = 1, int = 0);
    virtual ~VE();
    string GetMa();
    string GetTen();
    int GetNamsinh();
    int GetSotrochoi();
    void SetTen(string);
    void SetNamsinh(int);
    void SetSotrochoi(int);
    virtual int Tinhtien() = 0;
    virtual void Nhap();
    virtual void Xuat();
};
VE::VE(string m, string t, int n, int s)
{
    Ma = m;
    Ten = t;
    Namsinh = n;
    Sotrochoi = s;
}
VE::~VE() {}
string VE::GetMa()
{
    return Ma;
}
string VE::GetTen()
{
    return Ten;
}
int VE::GetNamsinh()
{
    return Namsinh;
}
int VE::GetSotrochoi()
{
    return Sotrochoi;
}
void VE::SetNamsinh(int n)
{
    Namsinh = n;
}
void VE::SetSotrochoi(int s)
{
    Sotrochoi = s;
}
void VE::SetTen(string t)
{
    Ten = t;
}
void VE::Nhap()
{
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, Ten);
    cout << "Nhap ma: ";
    getline(cin, Ma);
    cout << "Nam sinh: ";
    cin >> Namsinh;
}
void VE::Xuat()
{
    cout << "Ten : " << Ten << endl;
    cout << "Ma : " << Ma << endl;
    cout << "Sinh nam: " << Namsinh << endl;
}
class TRONGOI : public VE
{
    private:
    int Soluongve;
public:
    TRONGOI();
    ~TRONGOI();
    int Tinhtien();
    void Nhap();
    void Xuat();
};
TRONGOI::TRONGOI():VE(){}
TRONGOI::~TRONGOI() {}
int TRONGOI::Tinhtien()
{
    return 200000;
}

void TRONGOI::Nhap()
{
    VE::Nhap();
}
void TRONGOI::Xuat()
{
    VE::Xuat();
    cout<<"So tro choi: 30\n";
    cout << "Tien ve la: " << Tinhtien() << endl;
}
class TUNGPHAN : public VE
{
private:
int sotrochoi;
public:
    TUNGPHAN();
    ~TUNGPHAN();
    int Tinhtien();
    void Nhap();
    void Xuat();
};
TUNGPHAN::TUNGPHAN() : VE() {}
TUNGPHAN::~TUNGPHAN() {}
int TUNGPHAN::Tinhtien()
{
    return 70000 + sotrochoi * 20000;
}

void TUNGPHAN::Nhap()
{
    
    VE::Nhap();
    cout << "So tro choi: ";
    cin >> sotrochoi;
}
void TUNGPHAN::Xuat()
{
    VE::Xuat();
    cout << "So tro choi: "<<sotrochoi<<endl;
    cout << "Tien ve la: " << Tinhtien() << endl;
}
class CONGVIEN 
{
private:
   int n,m;
   TUNGPHAN *tp;
   TRONGOI *tg;
public:
    CONGVIEN();
    ~CONGVIEN();
    void Nhapds();
    void Xuatds()const ;
    float Tongtien();
    int Tongve();
};
CONGVIEN::CONGVIEN(){
    m=0;
    n=0;
    tp=NULL;
    tg=NULL;
}
CONGVIEN::~CONGVIEN(){
    delete[] tp;
    delete[] tg;
}
void CONGVIEN::Nhapds(){
    cout<<"Nhap so luong ve tung phan: ";
    cin>>n;
    tp=new TUNGPHAN[n];
    for (int i=0; i<n;i++){
        cout<<"Nhap thong tin ve tung phan: "<<endl;
        tp[i].Nhap();
    }
    cout<<"Nhap so luong ve tron goi: "<<endl;
    cin>>m;
    tg=new TRONGOI[m];
    for (int i=0; i<m; i++){
    cout<<"Nhap thong tin ve tron goi: "<<endl;
    tg[i].Nhap();
}}
void CONGVIEN::Xuatds()const {
    cout<<"Danh sach ve tung phan: \n";
    for (int i=0; i<n;i++){
        tp[i].Xuat();
        cout<<endl;
    }
    cout<<"Danh sach ve tron goi: \n";
    for (int i=0; i<m; i++){
        tg[i].Xuat();
        cout<<endl;
    }
}
float CONGVIEN::Tongtien(){
    float sum1=0, sum2=0, sum=0;
    for (int i=0; i<n; i++){
        sum1+= tp[i].Tinhtien();
    }
    for (int i=0;i<m;i++){
        sum2+=tg[i].Tinhtien();
    }
    sum=sum1+sum2;
    return sum;
}
int CONGVIEN::Tongve(){
    return n;
}
int main(){
   CONGVIEN cv;
    cout<<"Nhap danh sach ve:\n";
    cv.Nhapds();
    cout<<"Xuat danh sach ve:\n";
    cv.Xuatds();
    float t1=cv.Tongtien();
    cout<<"Tong so tien cong vien thu duoc la: "<<t1<<endl;
    int t2=cv.Tongve();
    cout<<"Tong so ve thanh phan da ban la: \n"<<t2<<endl;
    return 0;
}