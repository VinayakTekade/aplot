#ifndef APLOTS_H
#define APLOTS_H 1
#include<vector>
#include<math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;
/// routine functions -------------------------------//
vector<float> linspace(float x1, float x2, int N);
void make_directory_if_do_not_exist(string path);
void remove_directory_and_sub_directories(string dir);
/// routine functions -------------------------------//
class DrawEPS
{
vector< vector<float> >xdata,ydata;
vector<int>lt,pt;vector<float>lw,ps; vector<string>col,leg;
ofstream fout;
public:
DrawEPS(float win,float hin);
DrawEPS();
void set_title(string lab,string col, string c);
void set_xlabel(string lab, string off, float xoff,float yoff,string colo,string c);
void set_ylabel(string lab,string off, float xoff,float yoff,string colo,string c);
void set_label(string lab, string at_or_at_screen, float atx,float aty,string rot,float rotdeg, string dum, string c);
void set_xtics(float x1,float dx, float x2);
void set_ytics(float y1,float dy, float y2);
void set_key(string tb,string lr,string bn,string ht, float h);
inline void unset_key(){fout<<"unset key"<<endl;}
void set_command(string com);
void set_data(vector <float>x,vector<float>y,string ltlw,int ltt,float lww, string ptps,int ptt,float pss, string colr, string c, string legend,string t);
void generate_plot(string fn);
};
class Line
{
public:
float xa,ya,za,xb,yb,zb,lw;
string col;
void set(float x0,float y0,float z0,float x1,float y1,float z1,float lw, string col);
};
class Quad
{
public:
int fill,border;
float trans;
Quad()
    {
    trans=0.5;//default transparancy;
    fill=1;
    border=0;
    }
inline void set_border_fill_transparancy(int b,int f,float t){border=b;fill=f;trans=t;}
float xa,ya,za,xb,yb,zb,xc,yc,zc,xd,yd,zd;
string col;

void set(float xa,float ya,float za,float xb,float yb,float zb,float xc, float yc, float zc, float xd,float yd,float zd,string col);
void draw_quad(ofstream &,int id);
};

class Circle
{
public:    
float x0,y0,z0,nx,ny,nz,R;
float ux,uy,uz,vx,vy,vz;
int nu;
string col;
void set(float R,float x0,float y0,float z0,float nx,float ny,float nz,int nu,string col);
void draw_circle(ofstream &);
};
class Cylinder
{
public: 
Circle Base;
float H;
int nv;
string col;
void set(float R,float x0,float y0,float z0,float nx,float ny,float nz,float H, int nu,int nv, string col);
void draw_cylinder(ofstream & fout);
};
class Data_4D
{
string fn;
public:
string fn_();
void set(string fn);
};

class Draw
{
vector<Line>lin;
vector<Circle>circ;
vector<Cylinder>cylin;
vector<Data_4D>dat_4d;
int set_xrange,set_yrange,set_zrange,set_logo,set_title;
float xmin,xmax,ymin,ymax,zmin,zmax,titlefs;
string logofile,title;
public:
Draw();
Draw(string title,float fs);
Draw(string title,float fs,string Logo);
void set_line(string Pa,float xa,float ya,float za,string Pb,float xb,float yb,float zb,string,float lw, string lc, string col);
void set_line(string Pa,vector<float> a,string Pb,vector<float> b,string,float lw, string lc, string col);
void set_circle(string rad,float R,string cen,float x0,float y0,float z0,string nor,float nx,float ny,float nz,string,int,string,string);
void set_cylinder(string rad,float R,string cen,float x0,float y0,float z0,string nor,float nx,float ny,float nz,string len,float H,
                  string,int,string, int, string,string);
void set_data_4d(string fn);
void reset_data_4d(string fn); // removes all existing and start fresh
void xrange(float a,float b);
void yrange(float a,float b);
void zrange(float a,float b);
void set_commands(ofstream &fout,float,float);
void generate_qt_plot(string pix,int wpx,int hpx,string view,float az, float el);
void generate_png_plot(string pix,int wpx,int hpx,string view,float az, float el,string fn,string fpng);
void generate_jpg_plot(string pix,int wpx,int hpx,string view,float az, float el,string fn,string fjpg);
};

class MultiPlot
{
ofstream fout;
vector<string>imagefile;
string title,abcd_font,abcd_col;
int wpx,hpx,nrow,ncol,abcd_yes;
float win,hin,lht,tht,wextra;
public:
MultiPlot(int nrow,int ncol, string title,string font,string col);
void im_pix(string fn,int & wx, int & hx);
void set_plot(string fimage);
void set_logo_wfrac(string fn,float w);
void system_command(string fn);
void inscribe_abcd(string font, string col);
void generate_multiplot(string fn);
};

class Anim
{
int nf,first_index;
public:
Anim(int nf)
{
    Anim::nf=nf;
    remove_directory_and_sub_directories("tempanim");
    make_directory_if_do_not_exist("tempanim/images/");
    first_index=pow(10,int(log10(nf)));
}
void generate_plot(DrawEPS & P,int fno)
{
ostringstream oss; 
oss.str(""); oss.clear();
oss<<"tempanim/images/frame"<<first_index+fno<<".pdf";
P.generate_plot(oss.str().c_str());
}
void generate_animated_gif(string dum1,int delms,string dum2, int loop,string fgif)
{
cout<<"# genererating animated gif ':"<<fgif<<"' ...."<<endl;
ostringstream oss; 
oss.str(""); oss.clear();
oss<<"convert -alpha deactivate -delay "<<delms<<" -loop "<<loop<<" -density 300 tempanim/images/*.pdf "<<fgif;
system(oss.str().c_str());
cout<<"#\t\t done"<<endl;
}
};
#endif
