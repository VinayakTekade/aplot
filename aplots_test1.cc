/*
 *  aplot library tesing lines and point types 
*/
///
#include<Libs/aplot.h> /// change path according to where aplot.h is located 
/// Dependencies (Assume that you have this!)
/// 1. Latex 
/// 2. Gnuplot
/// 3. ImageMagik 
int main()
{
vector<float> x=linspace(0,10,11);
vector<float> y1=linspace(1,11,11);
vector<float> y2=linspace(2,12,11);
vector<float> y3=linspace(3,13,11);
vector<float> y4=linspace(4,14,11);
vector<float> y5=linspace(5,15,11);
vector<float> y6=linspace(6,16,11);
vector<float> y7=linspace(7,17,11);
vector<float> y8=linspace(8,18,11);
vector<float> y9=linspace(9,19,11);
vector<float> y10=linspace(10,20,11);

Aplot AP(6,4);
/// Data
AP.set_data(x,y1,"ltw",1,2,"pts",1,2,"col","R1","title", "$R_1$");
AP.set_data(x,y2,"ltw",2,2,"pts",2,2,"col","R2","title", "$R_2$");
AP.set_data(x,y3,"ltw",3,2,"pts",3,2,"col","R3","title", "$R_3$");
AP.set_data(x,y4,"ltw",4,2,"pts",4,2,"col","G1","title", "$G_1$");
AP.set_data(x,y5,"ltw",5,2,"pts",5,2,"col","G2","title", "$G_2$");
AP.set_data(x,y6,"ltw",6,2,"pts",6,2,"col","G3","title", "$G_3$");
AP.set_data(x,y7,"ltw",7,2,"pts",7,2,"col","B1","title", "$B_1$");
AP.set_data(x,y8,"ltw",8,2,"pts",8,2,"col","B2","title", "$B_2$");
AP.set_data(x,y9,"ltw",9,2,"pts",9,2,"col","B3","title", "$B_3$");
AP.set_data(x,y10,"ltw",10,2,"pts",10,1,"col","BB","title", "$BB$");
// Labels
AP.set_xlabel("\\large $x^2-\\sigma$","off",0,0.5,"col","R1");//other options: \\tiny \\scriptsize \\Huge...
AP.set_ylabel("\\large $y^2-\\sigma$","off",0,0,"col","R1");
AP.set_title("\\huge APLOT: Line Colors and Point Types","col","R1");
AP.set_label("\\large $\\sum_{k=1}^K \\frac{a_k}{b_k}$","at screen",0.75,0.25,"rotdeg",15,"col","R1");
AP.set_label("\\large Hello World","at screen",0.5,0.22,"rotdeg",45,"col","B2");
///Legend
AP.set_command("set key vertical maxrows 3 top left box samplen 2 spacing 1.5"); 
AP.generate_plot("myimages/test_lines_points.pdf");
/// Illustrate other line types
}
