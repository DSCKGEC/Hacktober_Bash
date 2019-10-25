class Adder
{
	public static void main(String args[])
	{
		int i, sum=0;
		if(args.length>1)
		{
			for(i=0; i<args.length; i++)
			{
				sum = sum + Integer.parseInt(args[i]);
			}
			System.out.println(sum);
		}
		else
			System.out.println("Error");
	}
}