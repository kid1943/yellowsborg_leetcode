//java
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


//java1
public class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] mark = new boolean[24 * 60];
        for (String time : timePoints) {
            String[] t = time.split(":");
            int h = Integer.parseInt(t[0]);
            int m = Integer.parseInt(t[1]);
            if (mark[h * 60 + m]) return 0;
            mark[h * 60 + m] = true;
        }
        
        int prev = 0, min = Integer.MAX_VALUE;
        int first = Integer.MAX_VALUE, last = Integer.MIN_VALUE;
        for (int i = 0; i < 24 * 60; i++) {
            if (mark[i]) {
                if (first != Integer.MAX_VALUE) {
                    min = Math.min(min, i - prev);
                }
                first = Math.min(first, i);
                last = Math.max(last, i);
                prev = i;
            }
        }
        //最后还要跟首尾元素差值进行比对
        min = Math.min(min, (24 * 60 - last + first));
        
        return min;
    }
}


//java2
public class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        List<Time> times = new ArrayList<>();
        for (String tp : timePoints) {
            String[] strs = tp.split(":");
            times.add(new Time(Integer.parseInt(strs[0]), Integer.parseInt(strs[1])));
        }
        Collections.sort(times);
        Time earlist = times.get(0);
        times.add(new Time(earlist.h + 24, earlist.m));//将最小的时间加到末尾
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int diff = (int) Math.abs(times.get(i).getDiff(times.get(i + 1)));
            minDiff = Math.min(minDiff, diff);
        }
        return minDiff;
    }
    
}

class Time implements Comparable<Time> {
    int h;
    int m;
    public Time(int h, int m) {
        this.h = h;
        this.m = m;
    }
    
    public int compareTo(Time other) {
        if (this.h == other.h) {
            return this.m - other.m;
        }
        return this.h - other.h;
    }
    
    public int getDiff(Time other) {
        return (this.h - other.h) * 60 + (this.m - other.m);            
    }
}











//c++
class Solution {
public:
    int findMinDifference(vector<string>& times) {
        int n = times.size();
        sort(times.begin(), times.end());
        int mindiff = INT_MAX;
        for (int i = 0; i < times.size(); i++) {
            int diff = abs(timeDiff(times[(i - 1 + n) % n], times[i]));
            diff = min(diff, 1440 - diff);
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }

private:
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};
//times[(i - 1 + n) % n], times[i]  前与后

