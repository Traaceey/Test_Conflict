#include <iostream>
#include <math.h>
using namespace std;
#define PI atan(1)*4
#define epsilon 0.0000000001
class DIEM
{
    private:
        double x,y;
        static int dem;
    public:
    ~DIEM();
    DIEM(double = 0, double =0);
    DIEM(const DIEM&);
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    double GetX() const;
    double GetY() const;
    static int GetDem();
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    bool KiemTraTrung(const DIEM&) const;
    double TinhKhoangCach (const DIEM&) const;
    DIEM TimDiemDoiXung( ) const;
    bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
    bool KiemTraTamGiacHopLe(double, double, double) const;
    double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
    double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
    string PhanLoaiTamGiac (const DIEM&, const DIEM&) const;
    friend istream& operator>>(istream&, DIEM&);
    friend ostream& operator<<(ostream&, DIEM&);
};
int DIEM::dem=0;
DIEM::~DIEM(){
    dem--;
    //cout<<"Da huy 1 diem => con "<<--dem<< " diem\n";
}
DIEM::DIEM(double xx, double yy) {
x=xx;
y=yy;
dem++;
}
void DIEM::SetX(double x){
    this->x=x;
}
void DIEM::SetY(double y){
    this->y=y;
}
void DIEM::SetXY(double x, double y){
   SetX(x);
   SetY(y);
}
double DIEM::GetX() const {
    return x;
}
double DIEM::GetY() const {
    return y;
}
int DIEM::GetDem() {
    return dem;
}
void DIEM::Nhap(){
    cout<<"Nhap hoanh do: ";
    cin>>x;
    cout<<"Nhap tung do: ";
    cin>>y;
}
void DIEM::Xuat() const {
    cout<<"("<<x<<" , "<<y<<" )";
}
void DIEM::DiChuyen(double dx, double dy){
    x+=dx;
    y+=dy;
}
bool DIEM::KiemTraTrung(const DIEM &d) const {
    return x==d.x && y==d.y;
}
double DIEM::TinhKhoangCach(const DIEM& d) const{
    return sqrt(pow(x-d.x,2) + pow(y-d.y,2));
}
DIEM DIEM::TimDiemDoiXung() const {
    return DIEM (x==0 ? x:-x, y==0 ? y:-y);
}
bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const {
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c= d2.TinhKhoangCach(*this);
    return a>0 && b>0 && c>0 && a+b>c && b+c > a && a+c>b;
}
double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const {
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return KiemTraTamGiacHopLe(d1,d2) ? a+b+c :0;
}
double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const {
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = (a+b+c)/2;
    return KiemTraTamGiacHopLe(d1,d2)? sqrt(p*(p-a)*(p-b)*(p-c)):0;
}
string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const{
    string kq;
    if (!KiemTraTamGiacHopLe(d1,d2))
        kq="Tam giac khong hop le";
    else 
    {
        double a = TinhKhoangCach(d1);
        double b = d1.TinhKhoangCach(d2);
        double c = d2.TinhKhoangCach(*this);
         if (a==b&& b==c)
		kq="Tam giac deu";
	    else if (a==b || b==c || c==a)
		    if (abs(a*a+b*-c*c)<= epsilon || abs(a*a+c*c-b*b)<=epsilon || abs(b*b+c*c-a*a)<= epsilon )
			kq="Tam giac vuong can";
		    else kq = " Tam giac can"; 	
	    else if (abs(a*a+b*-c*c)<= epsilon || abs(a*a+c*c-b*b)<=epsilon || abs(b*b+c*c-a*a)<= epsilon )
		kq="Tam giac vuong";
	    else kq="Tam giac thuong";
    }
    return kq;
}
istream& operator>>(istream& is, DIEM& d){
    d.Nhap();
    return is;
}
ostream& operator<<(ostream& os, const DIEM& d){
    d.Xuat();
    return os;
}
class HTRON{
    private:
        static int dem;
    public:
        DIEM O;
        double R;
        ~HTRON();
        HTRON(double = 0, double =0, double = 1);
        HTRON(DIEM,double =1);
        void SetO(DIEM);
        void SetR(double);
        void SetHTRON(DIEM, double);
        DIEM GetO() const;
        double GetR() const;
        static int Getdem();
        void DiChuyen(double, double);
        double TinhChuVi() const;
        double TinhDienTich() const;
        friend istream& operator>>(istream&, HTRON&);
        friend ostream& operator<<(ostream&, HTRON&);
};

int HTRON::dem = 0;
HTRON::~HTRON(){
    cout<<"Huy HTRON\n";
    dem--;
}
HTRON::HTRON(double x, double y, double R) : O(x,y){
    SetR(R);
    dem++;
}
HTRON::HTRON(DIEM O, double R): O(0){
    SetR(R);
    dem++;
}
void HTRON::SetO(DIEM O){
    this->O=O;
}
void HTRON::SetHTRON(DIEM O, double R){
    SetO(O);
    SetR(R);
}
DIEM HTRON::GetO() const {
    return O;
}
double HTRON::GetR() const {
    return R;
}
int HTRON::Getdem(){
    return dem;
}
void HTRON::DiChuyen(double dx, double dy){
    O.DiChuyen(dx,dy);
}
double HTRON::TinhChuVi() const {
    return 2 * PI  * R;
}
double HTRON::TinhDienTich() const {
    return PI * R *R;
}
istream& operator>>(istream& is, HTRON& htron){
    cout<<"Nhap toa do tam O: \n";
    is>>htron.O;
    do{
        cout<<"Nhap ban kinh R>0: ";
        is>>htron.R;
    } while (htron.R<=0);
    return is;
}
ostream& operator<<(ostream& os, const HTRON& htron)
{
    os<<"Hinh tron tam O "<<htron.O<<", ban kinh R = "<<htron.R<<" => Chu vi = "<<htron.TinhChuVi()<<", Dien tich = "<<htron.TinhDienTich()<<endl;
    return os;
}
int main(){
    cout<<"So hinh tron hien tai la: "<<HTRON::Getdem()<<endl;
    HTRON ht1, ht2(DIEM(1,2),3), *ht3=new HTRON;
    cout<<"So hinh tron hien tai la: "<<HTRON::Getdem()<<endl;
    cout<<ht1<<ht2<<*ht3<<endl;
    cout<<"Nhap lai hinh tron 3: \n";
    cin>>*ht3;
    cout<<"Hinh tron 3 moi la: "<<*ht3<<endl;
    ht3->DiChuyen(-1,1);
    cout<<"Hinh tron 3 sau khi di chuyen (-1,1) laL "<<*ht3<<endl;
    system("pause");
    return 0;
}