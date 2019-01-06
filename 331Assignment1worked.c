/* ZHANG, HE, 16216941, Assignment 1, 159.331 */
/* explain what the program is doing . . . */
/* All test below followed instruction of assignment. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void wordCount(char*sentence);
void printWords(char*sentence);
void strAppend(char*a,char*b);
void getIdentifier(char *l,char *id,int startP,char sep);
int equal(char *k,char *w);
void getWord(char *l, char *k, int pos);
void getValue(char *l,char *v,int p);
void addList(struct Node **l, char *id, char *v);
void printList(struct Node *l);
void printNumEle(struct Node *l);
int findId(struct Node *l, char *id, char *v);
void getsearchID(char *l,char *id,int pos);
void updateLL(struct Node **l,char *id, char *v);
void reverseLL(struct Node **l);
void reverseEntireString(char *s,char *p);
void reverseEachWords(char *s);


struct Node{
	struct Node *next;
	char *data;
	char *name;
};



int main(int argc,char * argv[]){
	
	printf("----------------------------------------\n");
	printf(" 159.331 Assignment 1 Semester 1 2018 \n");
	printf(" Submitted by:   HE ZHANG,  16216941  \n");
	printf("----------------------------------------\n");
	
	char appendValue[1000];
	char idValue[1000];
	char command[1000];
	char value[1000];
	char identifier[1000];
	char keyword[1000];
	char searchValue[1000];
	char searchID[1000];
	char firstValue[1000];
	struct Node *commandList=NULL;
	int found=0;
	
	
	while(fgets(command, 100, stdin)!=NULL){
		//function to seperate the keyword from command
		getWord(command,keyword,0);
		//compare keyword with user input
		if(equal(keyword,"exit")){
			printf("Program exiting...\n");
			printList(commandList);
			break;
		}else if(equal(keyword,"set")){
			//seperate identifier from command
			getIdentifier(command,identifier,4,' ');
			char *tempId =strdup(identifier);
			int posi=strlen(identifier)+5;
			//check quotation mark
			if(command[posi]=='\"'){
				//seperate value from command
				getIdentifier(command,value,posi+1,'\"');
				char *tempVal=strdup(value);
				//add identifier and value to Linked List.
				addList(&commandList,tempId,tempVal);
				
			}else{
				getWord(command,searchID,posi);
				//space posi
				posi=posi+strlen(searchID);
				found=findId(commandList,searchID,firstValue);
				if(found){
					//posi will skip identifier length and " + " length.
					while(command[posi]!=';'){
						posi=posi+3;
						getWord(command,searchID,posi);
						if(equal(searchID,"SPACE")){
							strAppend(firstValue," ");
						}else if(equal(searchID,"TAB")){
							strAppend(firstValue,"\r");
						}else if(equal(searchID,"NEWLINE")){
							strAppend(firstValue,"\n");
						}else{
							found=findId(commandList,searchID,searchValue);
							if(found){
								char *tempValue2=strdup(searchValue);
								strAppend(firstValue,tempValue2);
							}else{
								fprintf(stderr,"identifier can not find\n");
								break;
							}
						}
						posi=posi+strlen(searchID);
					}
					if(found){
						char *tempValue=strdup(firstValue);
						addList(&commandList,tempId,tempValue);
					}
				}else{
					fprintf(stderr,"identifier can not find\n");
				}
			}
		}else if(equal(keyword,"append")){
			int position=7;
			getIdentifier(command,searchID,position,' ');
			found=findId(commandList,searchID,idValue);
			char *tempId=strdup(searchID);
			position=position+strlen(searchID)+1;
			if(found){
				if(command[position]=='\"'){
					position=position+1;
					//get the append value.
					getIdentifier(command,appendValue,position,'\"');
					strAppend(idValue,appendValue);
					char *tempV=strdup(idValue);
					updateLL(&commandList,tempId,tempV);
				}else{
					
					char ident[20];
					getWord(command,ident,position);
					//if keyword was found, return 1, else return 0;
					if(equal(ident,"SPACE")){
						strAppend(idValue," ");
					}else if(equal(ident,"TAB")){
						strAppend(idValue,"\r");
					}else if(equal(ident,"NEWLINE")){
						strAppend(idValue,"\n");
					}else{
						found=findId(commandList,ident,appendValue);
						strAppend(idValue,appendValue);
					}
					position=position+strlen(ident);
					if(found){
						while(command[position]!=';'){
							position=position+3;
							getWord(command,searchID,position);
							if(equal(searchID,"SPACE")){
								strAppend(idValue," ");
							}else if(equal(searchID,"TAB")){
								strAppend(idValue,"\r");
							}else if(equal(searchID,"NEWLINE")){
								strAppend(idValue,"\n");
							}else{
								found=findId(commandList,searchID,searchValue);
								if(found){
									char *tempValue2=strdup(searchValue);
									strAppend(idValue,tempValue2);
								}else{
									fprintf(stderr,"identifier can not find\n");
									break;
								}
							}
							position=position+strlen(searchID);
						}
						if(found){
							char *tempValue=strdup(idValue);
							updateLL(&commandList,tempId,tempValue);
						}
					}else{
					fprintf(stderr,"identifier can not find\n");
					}
				}
				
			}else{
				fprintf(stderr,"identifier can not find\n");
			}
		}else if(equal(keyword,"print")){
			getIdentifier(command,searchID,6,';');
			found=findId(commandList,searchID,idValue);
			if(found){
				printf("%s\n",idValue);
			}else{
				fprintf(stderr,"identifier can not find\n");
			}
		}else if(equal(keyword,"printwordcount")){
			getIdentifier(command,searchID,15,';');
			found=findId(commandList,searchID,idValue);
			if(found){
				wordCount(idValue);
			}else{
				fprintf(stderr,"identifier can not find\n");
			}
		}else if(equal(keyword,"printwords")){
			getIdentifier(command,searchID,11,';');
			found=findId(commandList,searchID,idValue);
			if(found){
				printWords(idValue);
			}else{
				fprintf(stderr,"identifier can not find\n");
			}
			
		}else if(equal(keyword,"printlength")){
			getIdentifier(command,searchID,12,';');
			found=findId(commandList,searchID,idValue);
			if(found){
				int count=strlen(idValue);
				printf("Length is: %d\n",count);
			}else{
				fprintf(stderr,"identifier can not find\n");
			}
			
		}else if(equal(keyword,"list")){
			//reverse linked list.
			reverseLL(&commandList);
			//print linked-list.
			printNumEle(commandList);
			printList(commandList);
			
		}else if(equal(keyword,"reverse")){
			getIdentifier(command,searchID,8,';');
			found=findId(commandList,searchID,idValue);
			if(found){
				char temp[1000];
				reverseEntireString(idValue,temp);
				reverseEachWords(temp);
				updateLL(&commandList,searchID,temp);
			}else{
				fprintf(stderr,"identifier can not find\n");
			}
			
		}else{
			fprintf(stderr,"error command, input again\n");
		}
	}
}

void addList(struct Node** l, char *id, char *v){
	
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	
	temp->name=id;
	temp->data=v;
	temp->next=(*l);
	(*l)=temp;
}

void reverseLL(struct Node **l){
    struct Node* prev   = NULL;
    struct Node* current = *l;
    struct Node* next = NULL;
    while (current != NULL){
		next  = current->next;  
		current->next = prev;   
		prev = current;
		current = next;
    }
    *l = prev;
}
void printNumEle(struct Node *l){
	struct Node *a;
	a=l;
	int i=0;
	while(a!=NULL){
		i++;
		a=a->next;
	}
	printf("Identifier List (%d)\n",i);
}


void printList(struct Node *l){
	struct Node *a;
	a=l;
	if(a==NULL){
		printf("List is empty\n");
		return;
	}
	while(a!=NULL){
		printf("%s: \"%s\"\n",a->name,a->data);
		a=a->next;
	}
}

void updateLL(struct Node **l,char *id, char *v){
	struct Node *temp=*l;
	while(temp!=NULL){
		if(equal(temp->name,id)){
			temp->data=v;
			return;
		}
		temp=temp->next;
	}
	(*l)=temp;
}


void getWord(char *l, char *k, int pos){
	int i=0;
	while((l[pos]!=' ')&&(l[pos]!=';')){
		k[i]=l[pos];
		i++;
		pos++;
	}
	k[i]='\0';
}

int equal(char *k,char *w){
	int i,lena,lenb;
	lena=strlen(k);
	lenb=strlen(w);
	if(lena==lenb){
		for(i=0;i<lena;i++){
			if(k[i]!=w[i]){
				return 0;
			}
		}
	}else{
		return 0;
	}
	return 1;
}


void getIdentifier(char *l,char *id,int startP,char sep){
	int j=0;
	while(l[startP]!=sep){
		id[j]=l[startP];
		startP++;
		j++;
	}
	id[j]='\0';
}

int findId(struct Node *l, char *id, char *v){
	struct Node *current;
	int find=0;
	current=l;
	while(true){
		if(current == NULL){break;}
		if(equal(current->name,id)){
			strcpy(v,current->data);
			find++;
		}
		current=current->next;
	}
	return find;
}


void strAppend(char*a,char*b){
	int i,lena,lenb;
	i=0;
	lena=strlen(a);
	lenb=strlen(b);
	for(i=0;i<lena;i++){
		a[i]=a[i];
	}
	for(i=lena;i<(lena+lenb);i++){
		a[i]=b[i-lena];
	}
	a[i]='\0';
}


void wordCount(char *sentence){
	int total,i;
	if(strlen(sentence)==0){
		total=0;
	}else{
		total=1;
	}
	int count =strlen(sentence);
	for(i=0;i<count;i++){
		if(sentence[i]==' '){
			total++;
		}
	}
	printf("Wordcount is:%d\n",total);
}
	
void printWords(char*sentence){
	int i=0;
	char temp[50];
	while(sentence[i]!='\0'){
		if(sentence[i]!=' '){
			temp[i]=sentence[i];
		}else{
			temp[i]='\n';
		}
		i++;
	}
	temp[i]='\0';
	printf( "Words are: \n%s\n",temp);
}

void reverseEntireString(char *s,char *p){
	int i=0;
	int count=strlen(s)-1;
	while(s[i]!='\0'){
		p[i]=s[count];
		count--;
		i++;
	}
	p[i]='\0';
}

void reverseEachWords(char *s){
	char p;
	int i,j,k,len;
	i=0;
	len=strlen(s);
	for(j=0;j<len;j++){
		
		if((s[j]==' ')||(j==len-1)){
			if(j<len-1){
				k=j-1;
			}else{
				k=j;
			}
			while(i<k){
				p=s[i];
				s[i]=s[k];
				s[k]=p;
				i++;
				k--;
			}
			i=j+1;
		}
	}
}






