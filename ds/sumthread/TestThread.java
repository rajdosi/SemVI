public class TestThread {
	public static int a[] = new int[30];
	public static int sum = 0;
	public static void main(String args[]) {
		for (int i=0; i<30; i++) {
			a[i] = i;
		}
		ThreadDemo T1 = new ThreadDemo(a, 0);
		T1.start();
      
		ThreadDemo T2 = new ThreadDemo(a, 1);
		T2.start();
		
		try {
			T1.join();
			sum += T1.getSum();
			T2.join();
			sum += T2.getSum();
		} catch (Exception e) {
		}
		
		System.out.println("total");
		System.out.println(sum);
	}   
}
