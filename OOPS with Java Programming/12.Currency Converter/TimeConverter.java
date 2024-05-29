package time;
public class TimeConverter{ 
	public int  newTime;
	public int HourstoMinutes(int time){
		newTime = time * 60 ;
		return newTime;
	}
	public int MinutestoHours(int time ){
		newTime= time / 60;
		return newTime;
	}
	public int HourstoSeconds(int time){
		newTime = time * 3600;
		return newTime;
	}
	public int SecondstoHours(int time){
		newTime = time / 3600 ;
		return newTime;
	}
	
}