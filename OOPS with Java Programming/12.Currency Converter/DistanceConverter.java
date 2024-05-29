package distance;
import java.math.BigDecimal;
public class DistanceConverter {
	public double newDistance;
	public BigDecimal MetertoKM(int distance){
		BigDecimal numerator = new BigDecimal(distance);
		BigDecimal denominator = new BigDecimal(1000);
		BigDecimal result = numerator.divide(denominator);
		return result;
	}
	public double KMtoMeter(int distance){
		newDistance= distance * 1000;
		return newDistance;
	}
	public double MilestoKM(int distance){
		newDistance = distance * 1.60934 ;
		return newDistance;
	}
	public double KMtoMiles(int distance){
		newDistance = distance / 1.60934;
		return newDistance;
	}

}