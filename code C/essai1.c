#include "libgraphique.h"
#include <GL/glhlib.h>
#include <stdio.h>
#define COTE_MIN (WINDOW_WIDTH < WINDOW_HEIGHT ? WINDOW_WIDTH : WINDOW_HEIGHT)
int main(void){
	int i,n,m,t,xn1,yn1,xn2,yn2,xm1,ym1,xm2,ym2;
	printf("entrez le nombre de lignes:");
	scanf("%d",&n);
	printf("entrez le nombre de colonnes:");
	scanf("%d",&m);
	printf("entrez la taille des cases:");
	scanf("%d",&t);
	int marge_c=(WINDOW_WIDTH-(t*n))/2;
	int marge_h=(WINDOW_HEIGHT-(t*m))/2;
	start_graphics();
	set_drawing_color(color_BLACK);
	xn1=marge_c;
	yn1=marge_h;
	xm1=marge_c;
	ym1=marge_h;
	for(i=1;i<=n+1;i++){
		xn2=xn1+(m)*t;
		yn2=yn1;
		draw_line(xn1, yn1, xn2, yn2);
		yn1=yn1+t;
	}
	for(i=1;i<=m+1;i++){
		ym2=ym1+(n)*t;
		xm2=xm1;
		draw_line(xm1, ym1, xm2, ym2);
		xm1=xm1+t;
	}
	update_graphics();
	get_key();	
	stop_graphics();
	return 0;
}
