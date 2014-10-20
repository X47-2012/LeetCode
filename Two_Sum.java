import java.util.Arrays;
import java.util.Comparator;

public class Two_Sum {
	class pair{
		int num;
		int pointer;
	}
	
	private pair[] numList;
	
    public int[] twoSum(int[] numbers, int target) {
    	
    	numList=new pair[numbers.length];
    	for(int i=0;i<numbers.length;i++)
    	{
    		pair p=new pair();
    		p.num=numbers[i];
    		p.pointer=i+1;
    		numList[i]=p;
    	}
    	
    	Arrays.sort(numList, new Comparator<pair>() {
					public int compare(pair o1, pair o2) {
						if(o1.num<o2.num)
							return -1;
						else
							if(o1.num>o2.num)
								return 1;
							else
								return 0;
					}
		});
        int[] an=new int[2];
        int left=0;
        int right=numbers.length-1;
        
        while((left<right)&&(numList[left].num+numList[right].num!=target))
        {
        	if(left>=numbers.length||right<0)
        		break;
        	if(numList[left].num+numList[right].num<target)
        		left++;
        	else
        		if(numList[left].num+numList[right].num>target)
        			right--;
        }
        
        if(numList[left].pointer<numList[right].pointer)
        {
        	an[0]=numList[left].pointer;
        	an[1]=numList[right].pointer;
        }
        else
        {
        	an[1]=numList[left].pointer;
        	an[0]=numList[right].pointer;
        }
        return an;
    }
}