grammar sample;

options 
{
    backtrack	= true;
    memoize	= true;
    k= 2;

}

rollno 	:YEAR BRANCH NO
 {
	System.out.println("Entered no is in proper format"); 
 }
;


BRANCH: 'BCE' | 'BEE' |'BCL'
;

YEAR :	'0'..'9' '0'..'9'
    ;

NO :	'0'..'9' '0'..'9' '0'..'9'
    ;

