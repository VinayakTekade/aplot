#include<Libs/aplots.h>
vector<float> sin_wave(vector<float>x, float t)
{
vector<float>y(x.size());
for(int i=0;i<x.size();i++)
y[i]=sin(t-x[i]); // omega=beta=1.0;
return y;
}
int main()
{
/// Test 2d plots
vector<float> y,x=linspace(0,8.*M_PI,101);
int nframes=51;
Anim An(nframes);
for(int i=0;i<nframes;i++)
{
DrawEPS P;
P.set_xlabel("\\large $x$","off",0,0.5,"col","B1");
P.set_ylabel("\\large $w(x,t)$","off",0,0,"col","B1");
P.set_xtics(0,5,20);
P.set_ytics(-1,0.5,1.0);
P.set_title("Wave Equation: $w(x,t)=\\sin(\\omega t-\\beta x)$","col","G1");
P.unset_key();
y=sin_wave(x,(1./8)*i);
P.set_data(x,y,"ltw",1,2,"pts",-1,1,"col","R1","title","");
An.generate_plot(P,i);
}
An.generate_animated_gif("delay-ms",10,"loop",0,"test2.gif");
}
