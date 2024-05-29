package currency;
public class CurrencyConverter {
	public double newAmount;
	public double EurotoINR(int amount){
		newAmount = 89.2 * amount ;
		return newAmount;
	}
	public double DollartoINR(int amount){
		newAmount = 74.5 * amount ;
		return newAmount;
	}
	public double YentoINR(int amount){
		newAmount = 0.67 * amount;
		return newAmount;
	}
	public double INRtoEuro(int amount){
		newAmount = amount / 89.2 ;
		return newAmount;
	}
	public double INRtoDollar(int amount){
		newAmount = amount / 74.5 ;
		return newAmount;
	}
	public double INRtoYen(int amount){
		newAmount = amount / 0.67 ;
		return newAmount;
	}
}