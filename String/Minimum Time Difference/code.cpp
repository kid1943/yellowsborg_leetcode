public class Solution {
    public int findMinDifference(List<String> timePoints) {
      int minest = 24*60/2; 
      for(int i = 0; i < timePoints.size(); i++){
          for(int j = i+1; j < timePoints.size();j++ ){
              int min = findMin(timePoints.get(i), timePoints.get(j));
              if(min == 0){
                  return 0;
              }
              if(min < minest){
                  minest = min;
              }
          }
      }
      return minest;
    }
    
   public int findMin(String str0, String str1){
        int total_min0 = time2int(str0);
        int total_min1 = time2int(str1);
        return  subtract_abs(total_min0, total_min1);
   }
    
    int subtract_abs(int i0, int i1){
       int half = 24*60/2;
       int toltal = 24*60;
       int diff = Math.abs(i0 - i1);    
       if(diff > half){
           return toltal - diff;
       }else{
           return diff;
       }       
    }
    
    int time2int(String strTime){
        String[] times = strTime.split(":");
        int total_min = Integer.parseInt(times[0])*60 + Integer.parseInt(times[1]);
        return total_min;
    }
}