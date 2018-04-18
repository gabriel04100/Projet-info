/* pour compiler ce fichier:  gcc –o cocotte cocotte.c libgraphique.c –lglut –lGLU –lGL –lm */



/* indispensable pour compiler un programme utilisant la bibliothèque graphique: */
#include "libgraphique.h"
#include "libgraphique_fonts.h"
#include "libgraphique.c"
#include <unistd.h>
#include <stdio.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif
#define COTE_MIN (WINDOW_WIDTH < WINDOW_HEIGHT ? WINDOW_WIDTH : WINDOW_HEIGHT)
void sup_g(int li,int co,int t)
{//supprime cloison quand on tourne a gauche
        set_drawing_color(color_WHITE);
        draw_line(li-(t/2), co-(t/2), li-(t/2), co+(t/2));
         update_graphics();

}
void sup_d(int li,int co,int t)
{//supprime cloison quand on tourne a droite
    set_drawing_color(color_WHITE);
    draw_line(li+(t/2), co-(t/2), li+(t/2), co+(t/2)); update_graphics();
}
void sup_haut(int li,int co,int t)
{
    set_drawing_color(color_WHITE);
        draw_line(li-(t/2), co+(t/2), li+(t/2), co+(t/2));
         update_graphics();
}
void sup_bas(int li,int co,int t)
{
    set_drawing_color(color_WHITE);
        draw_line(li-(t/2), co-(t/2), li+(t/2), co-(t/2));
         update_graphics();
}
int main(void){

	int i,n,m,t,xn1,yn1,xn2,yn2,xm1,ym1,xm2,ym2;

	printf("entrez la taille du cote du carre:");

	scanf("%d",&n);

	m=n;
	printf("entrez la taille des cases:");

	scanf("%d",&t);
//calcul pour centrer la grille
	int marge_c=(WINDOW_WIDTH-(t*n))/2;

	int marge_h=(WINDOW_HEIGHT-(t*m))/2;
char index(char c,int x)
{
    c=x-'0';
    return c;
}
	start_graphics();

	set_drawing_color(color_BLACK);
//coordonnées des marges à prendre pour centrer
	xn1=marge_c;

	yn1=marge_h;

	xm1=marge_c;

	ym1=marge_h;


	for(i=1;i<=n+1;i++){
//dessin des lignes
		xn2=xn1+(m)*t;
		yn2=yn1;
		draw_line(xn1, yn1, xn2, yn2);
		/*if (i<=n){
            char *c=i-'0';
            draw_string(xn1-t,yn1+(t/2),&c);
		}*/
		yn1=yn1+t;

	}
	for(i=1;i<=m+1;i++){
//dessin des colonnes
		ym2=ym1+(n)*t;
		xm2=xm1;
		draw_line(xm1, ym1, xm2, ym2);
		/*if (i<=m){
            draw_string(xm1+(t/2),ym1-t,&i);
		}*/
		xm1=xm1+t;

	}
//j'ai cherché ici les coordonnees de debut et de fin
//draw_circle_full((xn1+(t/2)),(yn1-(1.5*t)),5);
//draw_circle_full((xm1-(1.5*t)),(ym1+(t/2)),5);
int li=xn1+(t/2);
int co=yn1-(1.5*t);
int finli=xm1-(1.5*t);
int finco=ym1+(t/2);update_graphics();
draw_circle_full(li,co,7);
update_graphics();

while((li<=finli)&&(co>=finco))
{
    if((get_key()==key_LEFT)&&(li>(xn1+(t/2))))
    {   li=li-t;
        draw_circle_full(li,co,7);
        sup_g(li+t,co,t);
        draw_circle_full(li+t,co,7);
        set_drawing_color(color_BLACK);
    }
    else if((get_key()==key_RIGHT)&&(li<xn2-(t/2)))
    {   li=li+t;
        draw_circle_full(li,co,7);
        sup_d(li-t,co,t);
        draw_circle_full(li-t,co,7);
        set_drawing_color(color_BLACK);
    }
    else if((get_key()==key_DOWN)&&(co>finco))
    {   co=co-t;
        draw_circle_full(li,co,7);
        sup_bas(li,co+t,t);
        draw_circle_full(li,co+t,7);
        set_drawing_color(color_BLACK);
    }
    else if((get_key()==key_UP)&&(co<yn1-(1.5*t)))
    {   co=co+t;
        draw_circle_full(li,co,7);
        sup_haut(li,co-t,t);
        draw_circle_full(li,co-t,7);
        set_drawing_color(color_BLACK);
    }
    else if (((get_key()==key_RIGHT))&&((li==finli)&& (co==finco)))
    {   li=li+t;
        draw_circle_full(li,co,7);
        sup_d(li-t,co,t);
        draw_circle_full(li-t,co,7);
        set_drawing_color(color_BLACK);
        sleep(20);
        stop_graphics();
    }

     update_graphics();

}


	return 0;

}
