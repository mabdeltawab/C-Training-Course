/* A menu-driven program for elementary database management */
#include <stdio.h>

void gotoxy(short col, short row);
main( )
{
FILE *fp, *ft ;
char another, choice ;
struct emp
{
char name[40] ;
int age ;
float bs ;
} ;
//Chapter 12: File Input/Output 443
struct emp e ;
char empname[40] ;
long int recsize ;
fp = fopen ( "EMP.DAT", "rb+" ) ;
if ( fp == NULL )
{
fp = fopen ( "EMP.DAT", "wb+" ) ;
if ( fp == NULL )
{
puts ( "Cannot open file" ) ;
exit(0) ;
}
}
recsize = sizeof ( e ) ;
while ( 1 )
{
//clrscr( ) ;
//gotoxy ( 30, 10 ) ;
printf ( "\n1. Add Records\n" ) ;
//gotoxy ( 30, 12 ) ;
printf ( "2. List Records\n" ) ;
//gotoxy ( 30, 14 ) ;
printf ( "3. Modify Records\n" ) ;
//gotoxy ( 30, 16 ) ;
printf ( "4. Delete Records\n" ) ;
//gotoxy ( 30, 18 ) ;
printf ( "0. Exit\n" ) ;
//gotoxy ( 30, 20 ) ;
printf ( "Your choice\n" ) ;
fflush ( stdin ) ;
choice = getche( ) ;
//444 Let Us C
switch ( choice )
{
case '1' :
fseek ( fp, 0 , SEEK_END ) ;
another = 'Y' ;
while ( another !='n' )
{
printf ( "\nEnter name, age and basic sal. " ) ;
scanf ("%s %d %f", e.name, &e.age, &e.bs ) ;
fwrite ( &e, recsize, 1, fp ) ;
//fprintf( fp,"\n    %s %d %8.1f     \n",e.name,e.age,e.bs);  /// originall it was fwrite  with file type binary
//fprintf( fp,"\n");
printf ( "\nAdd another Record (Y/N) " ) ;
fflush ( stdin ) ;
another = getche( ) ;
}
break ;
case '2' :
rewind ( fp ) ;
while ( fread ( &e, recsize, 1, fp ) == 1 )
printf ( "\n%s %d %f", e.name, e.age, e.bs ) ;
break ;
case '3' :
another = 'Y' ;
while ( another == 'Y' )
{
printf ( "\nEnter name of employee to modify " ) ;
scanf ( "%s", empname ) ;
rewind ( fp ) ;
while ( fread ( &e, recsize, 1, fp ) == 1 )
////Chapter 12: File Input/Output 445
{
if ( strcmp ( e.name, empname ) == 0 )
{
printf ( "\nEnter new name, age & bs" ) ;
scanf ( "%s %d %f", e.name, &e.age,
&e.bs ) ;
fseek ( fp, - recsize, SEEK_CUR ) ;
fwrite ( &e, recsize, 1, fp ) ;
break ;
}
}
printf ( "\nModify another Record (Y/N) " ) ;
fflush ( stdin ) ;
another = getche( ) ;
}
break ;
case '4' :
another = 'Y' ;
while ( another == 'Y' )
{
printf ( "\nEnter name of employee to delete " ) ;
scanf ( "%s", empname ) ;
ft = fopen ( "TEMP.DAT", "wb" ) ;
rewind ( fp ) ;
while ( fread ( &e, recsize, 1, fp ) == 1 )
{
if ( strcmp ( e.name, empname ) != 0 )
fwrite ( &e, recsize, 1, ft ) ;
}
fclose ( fp ) ;
fclose ( ft ) ;
/////446 Let Us C
remove ( "EMP.DAT" ) ;
rename ( "TEMP.DAT", "EMP.DAT" ) ;
fp = fopen ( "EMP.DAT", "rb+" ) ;
printf ( "Delete another Record (Y/N) " ) ;
fflush ( stdin ) ;
another = getche( ) ;
}
break ;
case '0' :
fclose ( fp ) ;
exit( 0) ;
}
}
}

