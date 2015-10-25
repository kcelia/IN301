#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>



typedef struct element {
	int val;
	struct element *svt; 
}liste;

/* struct element { int val; struct element* svt; }; 
 typedef struct element Eelement; 
 typedef Element* liste ;
 liste unitliste () { retrun NULL;} 
 dans le main liste l = unitliste(); sinon void inis2( liste * l) { *l=NULL;}
 dans le main inis2(&l);
 int estvide(liste l){
 return l==NULL}
 */
 
 int alea( int n)
 {int x; 
	 x=rand()%n; return x;}
	 
liste* inis(liste *l) {
	liste *p;
	p = malloc(sizeof(liste)); 
	p->val= 0;
	p->svt = NULL;
	l=p;
	return l;
}
void afficheliste( liste *l)
{   liste *p; p=l;
	 while (p != NULL ) 
	
	{     printf("%d\t",p->val); p=p->svt;  }
	
 }
 /* void affiche liste (liste l)
   {if (estvide(l) {printf("\n"); }
   else {printf("%d",l->svt);
   affiche liste (l->svt);} }*/
   
 int nbrliste ( liste *l){
	 liste*p=l; 
	 if (p==NULL) {return 0;}
	 else 
	 { p=p->svt; 
		   return nbrliste(p)  + 1;}
	 
	 //for( p=l,i=0;   p!=NULL;  p=p->svt,i++)
	 
	 
 }
 
 liste* ad(liste *l,int x)
 {  liste *p= malloc(sizeof(liste));
	 p->val = x; 
	 p->svt=l;
	 
	 return p;}
 
 liste *af(liste*l,int x)
 { liste*p=(liste*)malloc(sizeof(liste*)),*pp;
	 
	 
	if (p!=NULL) { p->val=x;
	 p->svt=NULL;
	 for (pp=l; pp->svt != NULL;pp=pp->svt);
	 pp->svt=p;
	 return l;}
	 else {return p;}
 }
 /* LISTE AJOUTFIN (LISTE L,INT E) { if ( listevide (l) ) return ad (l,e);
  l->svt = ajout fin (l->svt,e); return l; }*/

liste* am(liste*l,int e){
liste *nouveau=malloc(sizeof(liste)),*p=l,*pp=l;
nouveau->val=e; // if ( estvide(l) || e<=l->val) {return  ad(l,v);}
nouveau->svt=NULL; // l->svt=ajouttrie(l->svt,v); retrun l;
if (l==NULL) { return nouveau;}
if ( nouveau->val <= p->val){ad(l,e); return l;}
if (p->svt == NULL && nouveau->val >= p->val )   {af(l,e); return l;}

while ( p->svt !=NULL && p->val < e)
{   pp=p; 
	p=p->svt; }
	
	if (p->svt !=NULL) { nouveau->svt=p; pp->svt= nouveau; return l;  }
	
	af(l,e); return l;
}
 /*liste ajout () {
	liste l
liste* am2(liste*l,int e)
 { 
	 if((l==NULL) || (e<=l->val) ) {return ad(l,e);}
	 
	l->svt = am2(l->svt,e);
	 return l;} */
	       
  int main (void) 
{   
	liste *l=NULL;
	//int i; liste*ll=NULL;
	int ran=0;
	
	srand(time(NULL));
	
	l=inis(l); 
	//ll=inis(ll);afficheliste(ll);puts("");printf("le nombre d element de la liste 2 est %d\n",nbrliste(ll));
	/*ran =alea(10);
	while (ran!=0) 
	{   l=ad(l, ran);
		ran =rand()%11;
		}afficheliste(l); puts(""); */
	
	
	/* ran =alea(10);
	while (ran!=0) 
	{   ll=af(ll, ran);
		ran =rand()%11;
		}
	afficheliste(ll); puts("");*/
	/*for(i=1;i<9;i++)
	{ l=af(l,i);}puts("");
	afficheliste(l);puts("");
	puts("ajoute 16");
	l=am(l,16);
	afficheliste(l);*/
	
	ran =alea(10);
	while( ran !=0)
	{l=am(l,ran); ran=alea(10);}
	afficheliste(l);puts(""); puts("deuxieme methode");
	while( ran !=0)
	{l=am2(l,ran); ran=alea(10);}
	afficheliste(l);
		puts(""); 
		printf("le nombre d element de la liste 1 est %d\n",nbrliste(l));
	return 0;}
