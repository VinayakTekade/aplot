//
#include "aplots.h" 
//
void normalize(float & ux,float &uy, float &uz)
{
float m=sqrt(ux*ux+uy*uy+uz*uz);
ux=ux/m; uy=uy/m; uz=uz/m;
}
vector<float> linspace(float a, float b, int N)
{
    float h = (b - a) / (N-1);
    vector<float>x(N);
    for (int i=0; i<N;i++){x[i] = a+h*i;}
    return x;
}
vector<string> tokenize__string_spchar(string line,char spchar)
{
vector<string> tokens;
tokens.resize(0);
string token;    
stringstream check(line); 
while(getline(check,token,spchar)) {tokens.push_back(token);}
return tokens;
}

void make_directory_if_do_not_exist(string path)
{
ostringstream oss; 
string path2=path;
char *sc=&path[0u];
string subpath;
int count=0;
for(int i=0;i<(i+10);i++)
{
oss.str(""); oss.clear();
char *token=strsep(&sc,"/");
if(token==NULL)break;
count++;
}
sc=&path2[0u];
for(int i=0;i<(count-1);i++)
{
oss.str(""); oss.clear();
char *token=strsep(&sc,"/");
if(token==NULL)break;
if(i==0)subpath=token;
else
subpath=subpath+"/"+token;
oss.str(""); oss.clear();
oss<<"mkdir -p '"<<subpath<<"'"<<endl;
system(oss.str().c_str());
}
}
void remove_directory_and_sub_directories(string dir)
{
ostringstream oss; 
oss.str(""); oss.clear();
oss<<"rm -r -f "<<dir<<endl;
system(oss.str().c_str());
oss.str(""); oss.clear();
}
void gnuplot_load_fn(string fn)
{
string comand="gnuplot -persist\n";
FILE *pipe= popen(comand.c_str() , "w");
ostringstream oss;
oss.str(""); oss.clear();
oss<<"load '"<<fn<<"'"<<endl;
fprintf(pipe, "%s",oss.str().c_str());
fflush(pipe);
int r=pclose(pipe);
if(r<0)cout<<"# error in pclose(), while using unix pipes!"<<endl;
}
string tcolor(string col)
{    
if(col[0]=='B' && col[1]=='B')return "0,0,0";
if(col[0]=='R')
{
if(col[1]=='1')return "0.80000,0.14510,0.16078";//"204,37,41 "
if(col[1]=='2')return "0.85490,0.48627,0.18824";//"218,124,48 ;
if(col[1]=='3')return "0.57255,.14118,0.15686";//"146,36,40";
}
if(col[0]=='G')
{
if(col[1]=='1') return "0.24314,0.58824,0.31765";//"62,150,81";
if(col[1]=='2')return "0.58039,0.54510,0.23922";// "148,139,61";
//if(col[1]=='3')return "0.78039,0.91765,0.274510";// "199,234,70";
if(col[1]=='3')return "0.223529,1.000000,0.078431";
}
if(col[0]=='B')
{
if(col[1]=='1')return "0.22353,0.41569,0.30196";// "57,106,177";
if(col[1]=='2')return "0.41961,0.29804,0.60392";// "107,76,154";
//if(col[1]=='3')return ".4,.4,.6"; //"102,102,153";
if(col[1]=='3')return "0.24706,0.87843,0.81569";
}
cout<<"# color must be either <R/G/B><1/2/3> "<<endl;
exit(0);
}
string pcolor(string col)
{
if(col[0]=='B' && col[1]=='B')return "#000000";
if(col[0]=='R')
{
if(col[1]=='1')return "#CC2529";
if(col[1]=='2')return "#DA7C30";
if(col[1]=='3')return "#922428";
}
if(col[0]=='G')
{
if(col[1]=='1')return "#3D9651";
if(col[1]=='2')return "#948B3D";
//if(col[1]=='3')return "#C7EA46";
if(col[1]=='3')return "#39FF14";
}
if(col[0]=='B')
{
if(col[1]=='1')return "#396AB1";
if(col[1]=='2')return "#6B4C9A";
//if(col[1]=='3')return "#666699";
if(col[1]=='3')return "#3FE0D0";
}
cout<<"# color must be either <R/G/B><1/2/3> "<<endl;
exit(0);
}
string dash_type(int i)
{
ostringstream oss;oss.clear();oss.str("");
//if(i==1){oss<<3; return oss.str();}
//if(i==3){oss<<1; return oss.str();}
if(i<=5){oss<<i; return oss.str();}
if(i==6){oss<<"'-'"; return oss.str();}
if(i==7){oss<<"'._'"; return oss.str();}
if(i==8){oss<<"'-..'"; return oss.str();}
if(i==9){oss<<"'-...'"; return oss.str();}
if(i==10){oss<<"'-..-.'";  return oss.str();}
cout<<"# color must be either <R/G/B><1/2/3> "<<endl;
exit(0);
}
void point_index__type_size(int i, int & pt, float &ps)
{
if(i==1){pt=4; ps=0.9; return;}
if(i==2){pt=5; ps=1.05;return;}
if(i==3){pt=6; ps=1.;return;}
if(i==4){pt=7; ps=1.2;return;}
if(i==5){pt=8; ps=1.;return;}
if(i==6){pt=9; ps=1.35;return;}
if(i==7){pt=12; ps=1.1;return;}
if(i==8){pt=13; ps=1.33;return;}
if(i==9){pt=1; ps=0.95;return;}
if(i==10){pt=2; ps=0.95;return;}
cout<<"# pt must be >=1 && <= 10"<<endl;
exit(0);
}
string abcd(int index)
{
string alp="(a) (b) (c) (d) (e) (f) (g) (h) (i) (j) (k) (l) (m) (n) (o) (p) (q) (r) (s) (t) (u) (v) (w) (x) (y) (z)";
vector<string> tok=tokenize__string_spchar(alp,' ');
return tok[index];
}

DrawEPS::DrawEPS(float win,float hin)
{
xdata.resize(0);
ydata.resize(0);
lt.resize(0);
pt.resize(0);
lw.resize(0);
ps.resize(0);
col.resize(0);
leg.resize(0);
make_directory_if_do_not_exist("tempeps/");
fout.open("tempeps/pic.gnu");
cout<<"# DrawEPS object defined on canvas : "<<win<<" X "<<hin<<" inch "<<endl;
fout<<"set terminal epslatex size "<<win<<"in, "<<hin<<"in color"<<endl;
fout<<"set output 'tempeps/pic.tex'"<<endl;
//fout<<"set key height 0.3"<<endl;
fout<<"set grid"<<endl;
}
DrawEPS::DrawEPS()
{
float win=3;
float hin=2;
cout<<"# DrawEPS object on canvas "<<win<<" X "<<hin<<" inch "<<endl;
xdata.resize(0);
ydata.resize(0);
lt.resize(0);
pt.resize(0);
lw.resize(0);
ps.resize(0);
col.resize(0);
leg.resize(0);
make_directory_if_do_not_exist("tempeps/");
fout.open("tempeps/pic.gnu");
//fout<<"set terminal epslatex font ',"<<fs<<"pt' size "<<win<<"in, "<<hin<<"in color"<<endl;
fout<<"set terminal epslatex size "<<win<<"in, "<<hin<<"in color"<<endl;
//fout<<"set terminal epslatex font ',16pt' color"<<endl;
//fout<<"set size 3.0, 2.0"<<endl;
fout<<"set output 'tempeps/pic.tex'"<<endl;
//fout<<"set key height 0.3"<<endl;
fout<<"set grid"<<endl;
}
void DrawEPS::set_title(string lab,string col, string c)
{
ostringstream oss;oss.clear();oss.str("");
oss<<"{\\textcolor[rgb]{"<<tcolor(c)<<"}{"<<lab<<"}}";
fout<<"set title '"<<oss.str()<<"'"<<endl;
//set label 2 '\ft $5$\,meV'         at 1.38,4e9     rotate by  78.5 center tc ls 1
}

void DrawEPS::set_xlabel(string lab, string off, float xoff,float yoff,string colo,string c)
{
ostringstream oss;oss.clear();oss.str("");
oss<<"{\\textcolor[rgb]{"<<tcolor(c)<<"}{"<<lab<<"}}";
fout<<"set xlabel '"<<oss.str()<<"' offset "<<xoff<<","<<yoff<<endl;
/*
set xlabel '{\Large $x$}'
set ylabel '{\Large $e^{\alpha x}$}'
* set xlabel '{\textcolor[rgb]{204,37,41}$x^2-$ some text $\sigma$}' offset 0,1
*/
}
void DrawEPS::set_ylabel(string lab,string off, float xoff,float yoff,string colo,string c)
{
ostringstream oss;
oss.clear();oss.str("");
oss<<"{\\textcolor[rgb]{"<<tcolor(c)<<"}{"<<lab<<"}}";
fout<<"set ylabel '"<<oss.str()<<"' offset "<<xoff<<","<<yoff<<endl;
}
void DrawEPS::set_label(string lab, string at_or_at_screen, float atx,float aty,string rot,float rotdeg, string dum, string c)
{
ostringstream oss;oss.clear();oss.str("");
oss<<"{\\textcolor[rgb]{"<<tcolor(c)<<"}{"<<lab<<"}}";
fout<<"set label '"<<oss.str()<<"' "<<at_or_at_screen<<" "<<atx<<","<<aty<<" rotate by  "<<rotdeg<<" center"<<endl;
//set label 2 '\ft $5$\,meV'         at 1.38,4e9     rotate by  78.5 center tc ls 1
}
void DrawEPS::set_xtics(float x1,float dx, float x2)
{
fout<<"set xrange ["<<x1<<":"<<x2<<"]"<<endl;
fout<<"set xtics "<<x1<<","<<dx<<","<<x2<<endl;
}
void DrawEPS::set_ytics(float y1,float dy, float y2)
{
fout<<"set yrange ["<<y1<<":"<<y2<<"]"<<endl;
fout<<"set ytics "<<y1<<","<<dy<<","<<y2<<endl;
}
void DrawEPS::set_key(string tb,string lr,string bn,string ht, float h)
{
fout<<"set key "<<tb<<"  "<<lr<<" "<<bn<<"  height "<<h<<endl;
}
void DrawEPS::set_command(string com)
{
fout<<com<<endl;
}
void DrawEPS::set_data(vector<float> x,vector<float> y,string ltlw,int ltt,float lww, string ptps,int ptt,float pss, string colr, string c, string legend,string t)
{
xdata.push_back(x);
ydata.push_back(y);
lt.push_back(ltt);
lw.push_back(lww);
pt.push_back(ptt);
ps.push_back(pss);
col.push_back(pcolor(c));
leg.push_back(t);
}
void DrawEPS::generate_plot(string fn)
{
fout<<"plot ";
///---------------------------------------------------------//
/// make as many files as data
ostringstream oss;
int last=xdata.size()-1;
int ptt; 
float pss;
for(int i=0;i<xdata.size();i++)
{
vector<float> x=xdata[i];
vector<float> y=ydata[i];
//--------------------------------//
ofstream fouta;
oss.clear();oss.str("");
oss<<"tempeps/d"<<i;
fouta.open(oss.str().c_str());
for(int k=0;k<x.size();k++) 
fouta<<x[k]<<"  "<<y[k]<<endl;
fouta.close();
//---------------------------------//
fout<<"'"<<oss.str()<<"' u 1:2 ";
if(lt[i]>0 && pt[i]<0)fout<<"w l ";
if(lt[i]>0 && pt[i]>0)fout<<"w lp ";
if(lt[i]<0 && pt[i]>0)fout<<"w p ";
if(lt[i]<0 && pt[i]<0)fout<<"w p ";
if(lt[i]>0)
{
fout<<"dt "<<dash_type(lt[i])<<" ";
}
if(pt[i]>0)
{
point_index__type_size(pt[i], ptt,pss);
}

if(lt[i]>0 && lw[i]>0)fout<<"lw "<<lw[i]<<" ";
if(pt[i]>0)fout<<"pt "<<ptt<<" ";
if(pt[i]>0 && ps[i]>0)fout<<"ps "<<pss<<" ";
fout<<" lc rgb '"<<col[i]<<"' ";
fout<<" t '{"<<leg[i]<<"}' ";
if(i==last)fout<<endl; else fout<<", ";
}
fout<<"quit"<<endl;
fout<<"# done "<<endl;
fout.close();
///---------------------------------------------------------//
/// now generate doc.tex
/*
\documentclass{article}
\usepackage{graphicx,color}
\pagestyle{empty}
\begin{document}
\begin{figure}[h]
\input{./test.tex}
\end{figure}
\end{document}
*/
ofstream foutb;
foutb.open("tempeps/doc.tex");
foutb<<"\\documentclass[12pt]{article}"<<endl;
foutb<<"\\usepackage{graphicx,color}"<<endl;
foutb<<"\\pagestyle{empty}"<<endl;
//foutb<<"\\paperwidth = 3in"<<endl;
//foutb<<"\\paperheight = 2in"<<endl;
foutb<<"\\begin{document}"<<endl;
foutb<<"\\begin{figure}[h]"<<endl;
//foutb<<"\\LARGE"<<endl;
foutb<<"\\input{tempeps/pic.tex}"<<endl;
foutb<<"\\end{figure}"<<endl;
foutb<<"\\end{document}"<<endl;
foutb.close();
/// Next steps 
///from the currunt directory execute 
// 1, gnuplot tempeps/pic.gnu [testeps folder will now have  pic.tex pic.eps along with existing pic.gnu 
// 2. 
cout<<"# generating "<<fn<<" using epslatex terminal "<<endl;
cout<<"#\t executing gnuplot commands using system piping ..";
oss.str(""); oss.clear();
oss<<"gnuplot tempeps/pic.gnu"<<endl;
system(oss.str().c_str());
cout<<"... done"<<endl;
cout<<"#\t executing latex commands using system piping ..";
oss.str(""); oss.clear();
oss<<"latex -output-directory=tempeps  -interaction=batchmode  tempeps/doc.tex > tempeps/screendump"<<endl;
//oss<<"latex -output-directory=tempeps  tempeps/doc.tex"<<endl;
//oss<<"latex -output-directory=tempeps  tempeps/doc.tex > tempeps/screendump"<<endl;
system(oss.str().c_str());
cout<<"... done"<<endl;
oss.str(""); oss.clear();
cout<<"#\t executing dvips commands ..";
oss<<"dvips -q -E tempeps/doc.dvi -o tempeps/doc.ps"<<endl; 
system(oss.str().c_str());
cout<<"... done"<<endl;
oss.str(""); oss.clear();
cout<<"#\t executing epstopdf commands ..";
oss<<"epstopdf --outfile=tempeps/doc.pdf tempeps/doc.ps";
system(oss.str().c_str());
cout<<"... done"<<endl;
oss.str(""); oss.clear();
cout<<"#\t executing pdftops commands .."<<endl;
oss<<"pdftops -eps tempeps/doc.pdf tempeps/doc.eps";
system(oss.str().c_str());

vector<string> tok=tokenize__string_spchar(fn,'.');
string exts=tok[1];
oss.str(""); oss.clear();
if(exts[0]=='e')
{
cout<<"#\t copying the file tempeps/doc.eps to : "<<fn<<endl;
oss<<"cp tempeps/doc.eps "<<fn;
system(oss.str().c_str());
}
if(exts[0]=='p')
{
cout<<"#\t copying the file tempeps/doc.pdf to : "<<fn<<endl;
oss<<"cp tempeps/doc.pdf "<<fn;
system(oss.str().c_str());
}
if(exts[0]!='p' && exts[0]!='e')
{
cout<<"# Error in extension : "<<endl; exit(0);
} 
cout<<"#\t removing the temp directories .."<<endl;
oss.str(""); oss.clear();
//oss<<"rm -r -f tempeps";
//system(oss.str().c_str());
cout<<endl;
}


MultiPlot::MultiPlot(int nrow,int ncol, string title,string font,string col)
{
MultiPlot::nrow=nrow;
MultiPlot::ncol=ncol;
/// Note on ideal pixcel industry standard = 300 pix for 1 inch 
// assuming individual graphs are produced with
win=3;
hin=2; 
lht=0.3;//logo-ht in in;
tht=0.2;// title-ht in in
wextra=0.25; // an extra 0.25in is seen in individual graph
if(title=="")tht=0.0;
wpx=300*(win*ncol-wextra*(ncol-1));
hpx=300*(hin*nrow+tht+lht); 
/*
n = 3
# t: top margin in pixels
t = 75.0
# b: key height in pixels (bottom margin)
b = 300.0
# h: height of output in pixels
h = 150.0*n + t + b
*/
cout<<"# MultiPlot object defined nrow X ncol = "<<nrow<<"X"<<ncol<<endl;
make_directory_if_do_not_exist("tempmulplo/pic.gnu");
fout.open("tempmulplo/pic.gnu");
fout<<"reset"<<endl;
fout<<"set terminal pngcairo dashed enhanced size "<<wpx<<","<<hpx<<endl;
fout<<"set output 'tempmulplo/pic.png'"<<endl;
fout<<"set multiplot layout "<<nrow<<","<<ncol<<" title '"<<title<<"' font '"<<font<<"' tc rgb '"<<pcolor(col)<<"'"<<endl;
//{font "<font>{,<size>}"}
fout<<"unset xrange"<<endl;
fout<<"unset yrange"<<endl;
fout<<"unset zrange"<<endl;
fout<<"unset label"<<endl;
fout<<"unset xlabel"<<endl;
fout<<"unset ylabel"<<endl;
fout<<"unset border"<<endl;
fout<<"unset xtics"<<endl;
fout<<"unset ytics"<<endl;
fout<<"unset object"<<endl;
fout<<"unset key"<<endl;
imagefile.resize(0);
abcd_yes=0;
}

void MultiPlot::im_pix(string fn,int & wx, int & hx)
{
ostringstream oss;
oss.str(""); oss.clear();
oss<<"identify -format '%w %h' "<<fn<<" > tempmulplo/logosize";
system(oss.str().c_str());
ifstream fin;
fin.open("tempmulplo/logosize");
fin>>wx>>hx;
fin.close();
oss.str(""); oss.clear();
}

void MultiPlot::set_plot(string fimage)
{
//int wpx=300*(win*ncol);
//int hpx=300*(hin*nrow+tht+lht); 
/// from above
int index=imagefile.size();
int rowind=float(index)/ncol;
int colind=index-rowind*ncol;
float dx=(1./ncol);
float pht=nrow*hin+tht+lht; //pht => 1.0;
float dy=hin/pht;
float xorig=dx*colind-wextra*colind/(ncol*win);
float yorig=1.0-(lht/pht)-(1+rowind)*dy;
cout<<"#\t setting plot: "<<index<<" of multiplot "<<nrow<<"X"<<ncol<<" at scaled orig ("<<xorig<<","<<yorig<<") and scaled w X h = ("<<dx<<"X"<<dy<<")"<<endl;

///--------------------------------------------------//
/// integrity check
vector<string> tok=tokenize__string_spchar(fimage,'.');
string exts=tok[1];
cout<<"#\t setting image-file '"<<fimage<<"' at ["<<xorig<<","<<yorig<<"] with size ["<<dx<<","<<dy<<"]"<<endl;
ostringstream oss;
if(exts[0]=='e')
{
cout<<"#\t image-file is in eps format , converting to png format using 'convert' ..."<<endl;
oss.str(""); oss.clear();
oss<<"convert -density 288 "<<fimage<<" -background white -alpha background -flatten tempmulplo/conv"<<imagefile.size()<<".png";
//cout<<oss.str()<<endl;
system(oss.str().c_str());
cout<<"#\t .. done!"<<endl;
oss.str(""); oss.clear();
oss<<"tempmulplo/conv"<<imagefile.size()<<".png";
imagefile.push_back(oss.str());
}
else
{
cout<<"#\t image-file is in pdf format , converting to png format using 'pdftoppm' ..."<<endl;
oss.str(""); oss.clear();
//pdftoppm doc.pdf -f 1 myfile -png
oss<<"pdftoppm "<<fimage<<" -f 1 tempmulplo/conv"<<imagefile.size()<<" -png"; 
//cout<<oss.str()<<endl;
system(oss.str().c_str());
cout<<"#\t .. done!"<<endl;
oss.str(""); oss.clear();
oss<<"tempmulplo/conv"<<imagefile.size()<<"-1"<<".png";
imagefile.push_back(oss.str());
}
//if(abcd_yes>0)cout<<"abcd======"<<abcd(imagefile.size()-1)<<endl;
fout<<"set origin "<<xorig<<","<<yorig<<endl;
fout<<"set size "<<dx<<","<<dy<<endl;
if(abcd_yes>0)
{
fout<<"set label '"<<abcd(imagefile.size()-1)<<"' at screen "<<xorig+0.55*dx<<","<<yorig<<" offset "<<0<<","<<0<<" font '"<<abcd_font<<"' front tc '"<<pcolor(abcd_col)<<"'"<<endl;
}
fout<<"plot '"<<imagefile[imagefile.size()-1]<<"' binary filetype=png with rgbimage"<<endl;
fout<<"unset label"<<endl;
}
void MultiPlot::set_logo_wfrac(string fn,float w)
{
int wx,hx;
im_pix(fn,wx,hx);
cout<<"#\t setting logo for multiplot '"<<fn<<"' of width (relative to screen) : "<<w<<endl;
cout<<"#\t computed pix : "<<wx<<" X "<<hx<<endl;
float h=w*hx/wx;
float xorig=1-w;
float yorig=0.0;
fout<<"set origin "<<xorig<<","<<yorig<<endl;
fout<<"set size "<<w<<","<<(h/hpx)*wpx<<endl;
fout<<"plot '"<<fn<<"' binary filetype=png with rgbimage"<<endl;
fout<<"unset label"<<endl;
cout<<"#\t inscribed logo"<<endl;
}

void MultiPlot::system_command(string fn)
{
string comand=fn;
FILE *pipe= popen(comand.c_str() , "w");
fflush(pipe);
int r=pclose(pipe);
if(r<0)cout<<"# error in pclose(), while using unix pipes!"<<endl;
}
void MultiPlot::inscribe_abcd(string font, string col)
{
abcd_yes=1;
abcd_font=font;
abcd_col=col;
}
void MultiPlot::generate_multiplot(string fn)
{
fout<<"unset multiplot"<<endl;
fout<<"quit"<<endl;
fout.close();
ostringstream oss;
/*
system_command("gnuplot tempmulplo/pic.gnu");
ostringstream oss;
oss.str(""); oss.clear();
oss<<"cp tempmulplo/pic.gnu "<<fn;
system_command(oss.str());
exit(0);
*/

//oss.str(""); oss.clear();
//oss<<"gnuplot tempmulplo/pic.gnu"<<endl;
//system(oss.str().c_str());
gnuplot_load_fn("tempmulplo/pic.gnu");
oss.str(""); oss.clear();
oss<<"cp tempmulplo/pic.png "<<fn<<endl;
system(oss.str().c_str());
oss.str(""); oss.clear();
}


void Line::set(float xa,float ya,float za,float xb,float yb,float zb,float lw, string col)
{
Line::xa=xa;
Line::ya=ya;
Line::za=za;
Line::xb=xb;
Line::yb=yb;
Line::zb=zb;
Line::lw=lw;
Line::col=col;
}

void Quad::set(float xa,float ya,float za,float xb,float yb,float zb,float xc, float yc, float zc, float xd,float yd,float zd,string col)
{
Quad::xa=xa;
Quad::ya=ya;
Quad::za=za;
Quad::xb=xb;
Quad::yb=yb;
Quad::zb=zb;
Quad::xc=xc;
Quad::yc=yc;
Quad::zc=zc;
Quad::xd=xd;
Quad::yd=yd;
Quad::zd=zd;
Quad::col=col;
}

void Quad::draw_quad(ofstream & fout, int id)
{
fout<<"set object "<<id<<" polygon from "<<xa<<","<<ya<<","<<za<<" to "<<xb<<","<<yb<<","<<zb<<" ";
fout<<" to "<<xc<<","<<yc<<","<<zc<<" to "<<xd<<","<<yd<<","<<zd<<" ";
fout<<" to "<<xd<<","<<yd<<","<<zd<<" to "<<xa<<","<<ya<<","<<za<<endl;
//set object 13 fill solid 0.9 border lw 2 fc palette cb 85.25754
if(fill>0)
fout<<"set object "<<id<<" fill trans solid "<<trans;
else
fout<<"set object "<<id<<" empty "<<endl;
if(border>0)
fout<<" border ";
else
fout<<" noborder ";
fout<<"fc rgb '"<<col<<"'"<<endl;
}

void Circle::set(float R,float x0,float y0,float z0,float nx,float ny,float nz,int nu,string col)
{
normalize(nx,ny,nz);
Circle::R=R;
Circle::x0=x0;
Circle::y0=y0;
Circle::z0=z0;
Circle::nx=nx;
Circle::ny=ny;
Circle::nz=nz;
Circle::nu=nu;
Circle::col=col;
///  orthogonal vectorrs
//........first one arbitrary .......
if(nx == 0){ux=1; uy=0; uz=0;}
else
{
if(ny == 0){ux=0; uy=1; uz=0;}
else
{
if(nz == 0){ux=0; uy=0; uz=1;}
else{ux=-ny; uy=nx; uz=0;}
}
}
normalize(ux,uy,uz);
/// .... take cross product to generate the next ....
vx=ny*uz-uy*nz;
vy=-(nx*uz-ux*nz);
vz=nx*uy-ux*ny;
normalize(vx,vy,vz);
cout<<"# setting circle of radius R = "<<R<<" at center = ("<<x0<<" "<<y0<<" "<<z0<<"), ";
cout<<" and given normal = ("<<nx<<" "<<ny<<" "<<nz<<")\n\t=> orthogonal vectors = ("<<ux<<" "<<uy<<" "<<uz<<") ";
cout<<" and ("<<vx<<" "<<vy<<" "<<vz<<")"<<endl;
float test1=ux*vx+uy*vy+uz*vz;
float test2=ux*nx+uy*ny+uz*nz;
float test3=vx*nx+vy*ny+vz*nz;
if(test1!=0){cout<<"orthogonality failed!"<<endl; exit(0);}
if(test2!=0){cout<<"orthogonality failed!"<<endl; exit(0);}
if(test3!=0){cout<<"orthogonality failed!"<<endl; exit(0);}
}

void Circle::draw_circle(ofstream & fout)
{
vector<float>u=linspace(0.,2.*M_PI,nu);
int l=u.size()-1;
float x1,y1,z1,x2,y2,z2;
for(int i=0;i<u.size();i++)
{
x1=x0+R*ux*cos(u[i])+R*vx*sin(u[i]);
y1=y0+R*uy*cos(u[i])+R*vy*sin(u[i]);
z1=z0+R*uz*cos(u[i])+R*vz*sin(u[i]);
if(i<l)
{
x2=x0+R*ux*cos(u[i+1])+R*vx*sin(u[i+1]);
y2=y0+R*uy*cos(u[i+1])+R*vy*sin(u[i+1]);
z2=z0+R*uz*cos(u[i+1])+R*vz*sin(u[i+1]);
}
else
{
x2=x0+R*ux*cos(u[0])+R*vx*sin(u[0]);
y2=y0+R*uy*cos(u[0])+R*vy*sin(u[0]);
z2=z0+R*uz*cos(u[0])+R*vz*sin(u[0]);
}
fout<<"set arrow nohead from "<<x1<<","<<y1<<","<<z1<<" to "<<x1<<","<<y2<<","<<z2;
fout<<" filled front lw "<<2<<" lc rgb '"<<col<<"'"<<endl;
}
}
void Cylinder::set(float R,float x0,float y0,float z0,float nx,float ny,float nz,float H,int nu,int nv,string col)
{
Base.set(R,x0,y0,z0,nx,ny,nz,nu,col);
Cylinder::H=H;
Cylinder::nv=nv;
Cylinder::col=col;
}
void Cylinder::draw_cylinder(ofstream & fout)
{
vector<float> u=linspace(0.,2.*M_PI,Base.nu);
vector<float> v=linspace(0.,1,nv);
int l=u.size()-1;
int m=v.size()-1;
float x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4;
int id=1;
for(int k=0;k<m;k++)
{
for(int i=0;i<u.size();i++)
{
x1=Base.x0+Base.nx*H*v[k]+Base.R*Base.ux*cos(u[i])+Base.R*Base.vx*sin(u[i]);
y1=Base.y0+Base.ny*H*v[k]+Base.R*Base.uy*cos(u[i])+Base.R*Base.vy*sin(u[i]);
z1=Base.z0+Base.nz*H*v[k]+Base.R*Base.uz*cos(u[i])+Base.R*Base.vz*sin(u[i]);
x4=Base.x0+Base.nx*H*v[k+1]+Base.R*Base.ux*cos(u[i])+Base.R*Base.vx*sin(u[i]);
y4=Base.y0+Base.ny*H*v[k+1]+Base.R*Base.uy*cos(u[i])+Base.R*Base.vy*sin(u[i]);
z4=Base.z0+Base.nz*H*v[k+1]+Base.R*Base.uz*cos(u[i])+Base.R*Base.vz*sin(u[i]);

if(i<l)
{
x2=Base.x0+Base.nx*H*v[k]+Base.R*Base.ux*cos(u[i+1])+Base.R*Base.vx*sin(u[i+1]);
y2=Base.y0+Base.ny*H*v[k]+Base.R*Base.uy*cos(u[i+1])+Base.R*Base.vy*sin(u[i+1]);
z2=Base.z0+Base.nz*H*v[k]+Base.R*Base.uz*cos(u[i+1])+Base.R*Base.vz*sin(u[i+1]);
x3=Base.x0+Base.nx*H*v[k+1]+Base.R*Base.ux*cos(u[i+1])+Base.R*Base.vx*sin(u[i+1]);
y3=Base.y0+Base.ny*H*v[k+1]+Base.R*Base.uy*cos(u[i+1])+Base.R*Base.vy*sin(u[i+1]);
z3=Base.z0+Base.nz*H*v[k+1]+Base.R*Base.uz*cos(u[i+1])+Base.R*Base.vz*sin(u[i+1]);
}
else
{
x2=Base.x0+Base.nx*H*v[k]+Base.R*Base.ux*cos(u[0])+Base.R*Base.vx*sin(u[0]);
y2=Base.y0+Base.ny*H*v[k]+Base.R*Base.uy*cos(u[0])+Base.R*Base.vy*sin(u[0]);
z2=Base.z0+Base.nz*H*v[k]+Base.R*Base.uz*cos(u[0])+Base.R*Base.vz*sin(u[0]);
x3=Base.x0+Base.nx*H*v[k+1]+Base.R*Base.ux*cos(u[0])+Base.R*Base.vx*sin(u[0]);
y3=Base.y0+Base.ny*H*v[k+1]+Base.R*Base.uy*cos(u[0])+Base.R*Base.vy*sin(u[0]);
z3=Base.z0+Base.nz*H*v[k+1]+Base.R*Base.uz*cos(u[0])+Base.R*Base.vz*sin(u[0]);
}
//fout<<"set arrow nohead from "<<x1<<","<<y1<<","<<z1<<" to "<<x1<<","<<y2<<","<<z2;
//fout<<" filled front lw "<<2<<" lc rgb '"<<col<<"'"<<endl;
Quad Q;
Q.set(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,col);
Q.set_border_fill_transparancy(0,1,0.15);
Q.draw_quad(fout,id);
id++;
}//i, u
}//k, v
}
string Data_4D::fn_()
{
    return fn;
}
void Data_4D::set(string fn)
{
    Data_4D::fn=fn;
}
Draw::Draw()
{
lin.resize(0); circ.resize(0); cylin.resize(0); dat_4d.resize(0);
set_xrange=0; set_yrange=0; set_zrange=0;
set_title=0; set_logo=0;
}
Draw::Draw(string title,float fs)
{
lin.resize(0); circ.resize(0); cylin.resize(0); dat_4d.resize(0);
set_xrange=0; set_yrange=0; set_zrange=0;
set_title=1; set_logo=0;
Draw::title=title;
Draw::titlefs=fs;
}
Draw::Draw(string title,float fs,string logofile)
{
lin.resize(0); circ.resize(0); cylin.resize(0); dat_4d.resize(0);
set_xrange=0; set_yrange=0; set_zrange=0;
set_title=1; set_logo=1;
Draw::title=title;
Draw::titlefs=fs;
Draw::logofile=logofile;
}
void Draw::set_line(string Pa,float xa,float ya,float za,string Pb,float xb,float yb,float zb,string linw,float lw, string lc, string col)
{
Line  L;
L.set(xa,ya,za,xb,yb,zb,lw,col);
lin.push_back(L);
}
void Draw::set_line(string Pa,vector<float> a,string Pb,vector<float> b,string lww,float lw, string lcc, string lc)
{
set_line(Pa,a[0],a[1],a[2],Pb,b[0],b[1],b[2],lww,lw,lcc,lc);
}

void Draw::set_circle(string rad,float R,string cen,float x0,float y0,float z0,string nor,float nx,float ny,float nz,string dum1,int nu,string dum2,string col)
{
Circle C; C.set(R,x0,y0,z0,nx,ny,nz,nu,col);
circ.push_back(C);
}
void Draw::set_cylinder(string rad,float R,string cen,float x0,float y0,float z0,string nor,float nx,float ny,float nz,string len,float H,
    string dum1,int nu,string dum2,int nv, string dum3,string col)
{
Cylinder C; C.set(R,x0,y0,z0,nx,ny,nz,H,nu,nv,col);
cylin.push_back(C);
}
void Draw::set_data_4d(string fn)
{
//set palette rgbformulae 33,13,10
Data_4D D; D.set(fn);
dat_4d.push_back(D);
}
void Draw::reset_data_4d(string fn)
{
//set palette rgbformulae 33,13,10
dat_4d.resize(0);
Data_4D D; D.set(fn);
dat_4d.push_back(D);
}
void Draw::xrange(float a,float b){set_xrange=1;xmin=a; xmax=b;}
void Draw::yrange(float a,float b){set_yrange=1;ymin=a; ymax=b;}
void Draw::zrange(float a,float b){set_zrange=1;zmin=a; zmax=b;}
void Draw::set_commands(ofstream &fout,float az, float el)
{
if(set_logo>0)
{
fout<<"set multiplot layout "<<2<<","<<1<<" title '"<<title<<"' font 'Helvetica,14'"<<endl;
fout<<"set margins 0,0,0,0"<<endl;
fout<<"unset border"<<endl;
fout<<"unset tics"<<endl;
fout<<"set origin 0.7,0"<<endl;
fout<<"set size 0.2,.12"<<endl;
fout<<"plot '"<<logofile<<"' binary filetype=png with rgbimage notitle"<<endl;
fout<<"set origin 0,0"<<endl;
fout<<"set size 1,1"<<endl;
}
else
{
if(set_title>0) fout<<"set  title '"<<title<<"' font 'Helvetica,14'"<<endl;
}
fout<<"set view equal xyz"<<endl;
fout<<"set xyplane relative 0"<<endl;
fout<<"set view "<<az<<","<<el<<",3,3"<<endl; 
fout<<"set margins 0,0,0,0"<<endl;
fout<<"unset border"<<endl;
fout<<"unset tics"<<endl;
fout<<"unset colorbox"<<endl;
fout<<"unset key"<<endl;
fout<<"set hidden3d"<<endl;
if(set_xrange >0)fout<<"set xrange ["<<xmin<<":"<<xmax<<"]"<<endl; 
if(set_yrange >0)fout<<"set yrange ["<<ymin<<":"<<ymax<<"]"<<endl; 
if(set_zrange >0)fout<<"set zrange ["<<zmin<<":"<<zmax<<"]"<<endl; 
int nobject=0;

///
/// DRAW ALL LINES 
///
for(int i=0;i<lin.size();i++)
{
fout<<"set arrow nohead from "<<lin[i].xa<<","<<lin[i].ya<<","<<lin[i].za<<" to "<<lin[i].xb<<","<<lin[i].yb<<","<<lin[i].zb;
fout<<" filled front lw "<<lin[i].lw<<" lc rgb '"<<lin[i].col<<"'"<<endl;
}
///
/// DRAW ALL CIRCLES 
///
for(int k=0;k<circ.size();k++)
{
circ[k].draw_circle(fout);
nobject++;
}
///
/// DRAW ALL CYLINDERS 
///
for(int k=0;k<cylin.size();k++)
{
cylin[k].draw_cylinder(fout);
nobject++;
}
///
/// DRAW ALL 4D Data
///
for(int k=0;k<dat_4d.size();k++)
{
fout<<"unset parametric"<<endl;   
fout<<"unset style"<<endl;
fout<<"set pm3d"<<endl;
fout<<"set palette rgbformulae 33,13,10"<<endl;   
if(nobject>0)fout<<"replot "; else fout<<"splot ";
fout<<"'"<<dat_4d[k].fn_()<<"' u 1:2:3:4  with pm3d"<<endl;
nobject++;
}
}

void Draw::generate_qt_plot(string pix,int wpx,int hpx,string view,float az, float el)
{
string fn="objects/gplot";
make_directory_if_do_not_exist(fn);
ofstream fout;
fout.open(fn.c_str());
fout<<"reset"<<endl;
fout<<"unset multiplot"<<endl;
fout<<"set term qt size "<<wpx<<","<<hpx<<endl;
set_commands(fout,az,el);
if(set_logo>0)
fout<<"unset multiplot"<<endl;
fout.close();
gnuplot_load_fn(fn);
}
void Draw::generate_png_plot(string pix,int wpx,int hpx,string view,float az, float el,string fname,string fpng)
{
string fn="objects/gplot";
make_directory_if_do_not_exist(fn);
ofstream fout;
fout.open(fn.c_str());
fout<<"reset"<<endl;
fout<<"set terminal png enhanced size "<<wpx<<","<<hpx<<endl;
fout<<"set output '"<<fpng<<"'"<<endl;
fout<<"unset multiplot"<<endl;
set_commands(fout,az,el);
if(set_logo>0)
fout<<"unset multiplot"<<endl;
fout.close();
gnuplot_load_fn(fn);
}
void Draw::generate_jpg_plot(string pix,int wpx,int hpx,string view,float az, float el,string fname,string fjpg)
{
string fn="objects/gplot";
make_directory_if_do_not_exist(fn);
ofstream fout;
fout.open(fn.c_str());
fout<<"reset"<<endl;
fout<<"set terminal jpeg enhanced size "<<wpx<<","<<hpx<<endl;
fout<<"set output '"<<fjpg<<"'"<<endl;
fout<<"unset multiplot"<<endl;
set_commands(fout,az,el);
if(set_logo>0)
fout<<"unset multiplot"<<endl;
fout.close();
gnuplot_load_fn(fn);
}
