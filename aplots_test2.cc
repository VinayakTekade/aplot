#include<Libs/aplot.h>
int main()
{
/// Test 2d plots
vector<float> xd=linspace(0,10,11);
vector<float> yr1=linspace(-1,1,11);
vector<float> yr2=linspace(0,2,11);
vector<float>  yr3=linspace(1,-1,11);
vector<float>  yr4=linspace(2,0,11);

Aplot A;//(5,3.5);
A.set_data(xd,yr1,"ltw",1,2,"pts",1,1,"col","R1","title", "$R_1$");
A.set_data(xd,yr2,"ltw",1,2,"pts",2,1,"col","G2","title", "$G_2$");
A.set_xlabel("\\large $\\sigma$","off",0,0.5,"col","R1");
A.set_ylabel("\\large $\\Gamma+\\beta$","off",0,0,"col","R1");
A.set_command("set key below left box samplen 2 spacing 1"); 
A.generate_plot("myimages2/test1.pdf");

Aplot B;//(5,3.5);
B.set_data(xd,yr3,"ltw",1,2,"pts",1,1,"col","R1","title", "$R_1$");
B.set_data(xd,yr4,"ltw",1,2,"pts",2,1,"col","G2","title", "$G_2$");
B.set_xlabel("\\large $\\sigma$","off",0,0.5,"col","R1");
B.set_ylabel("\\large $\\beta+\\zeta$","off",0,0,"col","R1");
B.set_command("set key below left box samplen 2 spacing 1"); 
B.generate_plot("myimages2/test2.pdf");

//exit(0);
/*
 pdftoppm doc.pdf -f 1 myfile -png;
*/
MultiPlot MP(3,2,"Testing Multiplot (APLOT) ","Helvetica,36","R1");
//MultiPlot(int nrow,int ncol, string title,string font,string col)
MP.inscribe_abcd("Helvetica,20","BB");
MP.set_plot("myimages2/test1.pdf");
MP.set_plot("myimages2/test2.pdf");
MP.set_plot("myimages2/test1.pdf");
MP.set_plot("myimages2/test2.pdf");
MP.set_plot("myimages2/test1.pdf");
MP.set_plot("myimages2/test2.pdf");
MP.set_logo_wfrac("~/Logo/Logo5.png",0.15);
MP.generate_multiplot("myimages2/testmp.png");    
}
