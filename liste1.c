#include<stdlib.h>
#include<stdio.h>
#include<time.h>


typedef struct element { int val; struct element * svt;}Element;
typedef Element* liste;

liste inis_liste() { return NULL; }

   void affiche_liste(liste l)
   { if (l==NULL) { printf("NULL \n");}
	else { printf("%d ->  ",l->val); affiche_liste(l->svt);  }} 
	
	liste ajout_debut(liste l,int e)
	{   liste p=malloc(sizeof(liste));  
		 p->val=e;
		 p->svt=l;
		 return p;   }
		 
	int alea_liste(int n)  { return rand()%n;}
	
	int nbr_liste ( liste l){
	 liste p=l; 
	 if (p==NULL) {return 0;}
	 else  { p=p->svt;  return nbr_liste(p)  + 1;} }
		   
    int recherche_element_liste ( liste l, int v){
			 if (l==NULL) {return 0;}
			 if (l->val ==  v) {return 1;}                 //    return (l->val==v) || recherche_element_liste(l->svt,v);
			 return recherche_element_liste(l->svt,v); }  //
			
			 
	liste inverse_liste ( liste l)
	{ liste ll=inis_liste();
		while (l!=NULL)
		{ ll=ajout_debut(ll,l->val); 
			l=l->svt;}
			return ll; }
			
    liste ajout_milieu (liste l,int e)
 { 
	 if((l==NULL) || (e<=l->val) ) {return ajout_debut(l,e);}
	 
	l->svt =  ajout_milieu(l->svt,e);
	 return l;} 
	 
	liste ajout_fin (liste l,int e)
	{if (l==NULL) {return  ajout_debut(l,e);}
		l->svt=ajout_fin(l->svt,e); return l;  }
		
		liste tri_bulle( liste l)
		{ int n=nbr_liste(l),tmp;
	     liste p=l;
	     
	     while (n>0)
	     { while ( p->svt!=NULL )
			 {
				 if ( p->val>(p->svt)->val ) { tmp=p->val;
					                           p->val= (p->svt)->val;
					                           (p->svt)->val=tmp;
			                                   }
			                                   p=p->svt;	
			}n--; p=l;} 
			
			return l;}
			
	liste trie_a_bulle( liste l) {
		int cont = 1;
		liste tmp=l;
		while (cont) {
			cont=0; 
			l=tmp;
			while (l!=NULL && l->svt!=NULL){
				if (l->val >l->svt->val) { l->val echange l->svt->val  cont =1;}}
		return tmps;	}
	
	int nbr_premier ( int n) {
		int i=2,cmp=2; 
		while ( (cmp ==2)  && i<(n/2) + 1 )
		 { 
			 if(n%i==0) {cmp++;} 
			 i++;
	     }
	     
		if (cmp==2) {return 1;}
		else {return 0;}
		
	 }
		
 void crible_liste(liste l,int v)
 {   int o=0;
	 while ( l!=NULL ) {
	 if ((nbr_premier(l->val) == 1) && (v>(l->val) )) { printf("%d\t",l->val); o++;  }
	 l=l->svt;
	                }
	                   
	          printf("\n il existe %d nombre premier inferieur a %d\n",o,v);
	           }	
	                   	
	                   	
	liste supprimer_element_liste(liste l,int v)
	{ liste tmp;
		if(l==NULL) { return l;} 
	
		  if ( l->val == v ) 
		     { tmp=l->svt;
			   free(l);
			   return tmp; }
			   l->svt=supprimer_element_liste(l->svt,v);
			   return l;}
   
   liste supprimer_occ_element_liste(liste l, int v){
	   
	{   liste tmp;
		if(l==NULL) { return l;} 
		l->svt=supprimer_occ_element_liste(l->svt,v);
		if(l->val==v) { tmp=l->svt; free(l); l=tmp; }
		return l; }}
	
	
	liste concat(liste l1,liste l2)
	{ if ( l1==NULL) return l2;
	  l1->svt=concat(l1->svt,l2);
	  return l1;}
	  
	  
	  liste fusion_listes(liste l1,liste l2)
	  {
		  if ( l1==NULL ) return l2;
		  if (l2==NULL ) return l1;
		  
		  if ( l1->val < l2->val ) { l1->svt=fusion_listes(l1->svt,l2); return l1; }
		  l2 ->svt = fusion_listes(l1,l2->svt); return l2;
		  
		  }
		  
	typedef struct el_modulo
	 {  liste ls;
		int tab[30];
	  }EL_modulo;
	 
	 
int main () 
{ liste l =inis_liste();
srand(time(NULL));
  EL_modulo s;
  int r=10,i;
  s.ls=inis_liste();
  
   while (r!=0) 
	 {   s.ls=ajout_debut(s.ls, r);r =rand()%11;  }
	  affiche_liste(s.ls);
  
	
	
	 
	 /*while (r!=0) 
	 {   l=ajout_debut(l, r);r =rand()%11;  }
	  affiche_liste(l);
	
  	crible_liste(l,11); */
		

	/* puts("inverser la liste l "); l=inverse_liste(l);	affiche_liste(l);
	 puts("tri_ a_bulle");         l=tri_bulle(l);      affiche_liste(l);*/
	 
	 
	 
	 
	 
	
	
	return 0;}
