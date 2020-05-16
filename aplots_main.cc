#include<Libs/aplots.h>
int main()
{
/// Test 2d plots
vec xd=linspace(0,10,11);
vec yr1=linspace(-1,1,11);
vec yr2=linspace(0,2,11);
vec yr3=linspace(1,3,11);
vec yg1=linspace(2,4,11);
vec yg2=linspace(3,5,11);
vec yg3=linspace(4,6,11);
vec yb1=linspace(5,7,11);
vec yb2=linspace(6,8,11);
vec yb3=linspace(7,9,11);
vec ybb=linspace(8,10,11);

DrawEPS DEPS1;//(5,3.5);
DEPS1.set_data(xd,yr1,"ltw",1,2,"pts",1,1,"col","R1","title", "$R_1$");
DEPS1.set_data(xd,yr2,"ltw",1,2,"pts",2,1,"col","R2","title", "$R_2$");
DEPS1.set_data(xd,yr3,"ltw",1,2,"pts",3,1,"col","R3","title", "$R_3$");
DEPS1.set_data(xd,yg1,"ltw",1,2,"pts",4,1,"col","G1","title", "$G_1$");
DEPS1.set_data(xd,yg2,"ltw",1,2,"pts",5,1,"col","G2","title", "$G_2$");
DEPS1.set_data(xd,yg3,"ltw",1,2,"pts",6,1,"col","G3","title", "$G_3$");
DEPS1.set_data(xd,yb1,"ltw",1,2,"pts",7,1,"col","B1","title", "$B_1$");
DEPS1.set_data(xd,yb2,"ltw",1,2,"pts",8,1,"col","B2","title", "$B_2$");
DEPS1.set_data(xd,yb3,"ltw",1,2,"pts",9,1,"col","B3","title", "$B_3$");
DEPS1.set_data(xd,ybb,"ltw",1,2,"pts",10,1,"col","BB","title", "$BB$");
DEPS1.set_xlabel("\\large $x^2-\\sigma$","off",0,0.5,"col","R1");
DEPS1.set_ylabel("\\large $y^2-\\sigma$","off",0,0,"col","R1");
DEPS1.set_xlabel("\\large $x^2-\\sigma$","off",0,0.5,"col","R1");
DEPS1.set_title("\\large $y^2-\\sigma$","col","R1");
DEPS1.set_label("\\large $y^2-\\sigma$","at screen",0.5,0.5,"rotdeg",45,"col","R1");
DEPS1.set_command("set key top left box samplen 2 spacing 1"); 
DEPS1.generate_plot("test_solid_lines.eps");
//exit(0);
DrawEPS DEPS2;
DEPS2.set_data(xd,yr1,"ltw",1,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yr2,"ltw",2,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yr3,"ltw",3,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yg1,"ltw",4,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yg2,"ltw",5,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yg3,"ltw",6,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yb1,"ltw",7,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yb2,"ltw",8,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yb3,"ltw",9,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,yb3,"ltw",9,2,"pts",-1,1,"col","R1","title", "$R_1$");
DEPS2.set_data(xd,ybb,"ltw",10,2,"pts",-1,1,"col","BB","title", "$BB$");
DEPS2.set_xlabel("\\large $x^2-\\sigma$","off",0,0.5,"col","R1");
DEPS2.set_ylabel("\\large $y^2-\\sigma$","off",0,0,"col","R1");
DEPS2.set_command("set key top left box samplen 2 spacing 1"); 
DEPS2.generate_plot("test_dashed_lines.eps");
//exit(0);
/*
 pdftoppm doc.pdf -f 1 myfile -png;
*/
MultiPlot MP(3,2,"test","Helvetica,36","R1");
//MultiPlot(int nrow,int ncol, string title,string font,string col)
MP.inscribe_abcd("Helvetica,20","BB");
MP.set_plot("test_solid_lines.eps");
MP.set_plot("test_dashed_lines.eps");
MP.set_plot("test_solid_lines.eps");
MP.set_plot("test_dashed_lines.eps");
MP.set_plot("test_solid_lines.eps");
MP.set_plot("test_dashed_lines.eps");
MP.set_logo_wfrac("~/Logo/Logo5.png",0.15);
MP.generate_multiplot("testmp.png");

}
