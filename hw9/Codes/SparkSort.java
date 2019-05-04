import org.apache.spark.api.java.JavaRDD;
import org.apache.spark.api.java.function.Function;
import org.apache.spark.SparkConf;
import org.apache.spark.api.java.JavaSparkContext;


public class SparkSort {
    public static void main(String[] args) {
        SparkConf configuration = new SparkConf().setAppName("Distributed spark Sort").setMaster("yarn");
        JavaSparkContext javaspark = new JavaSparkContext(configuration);
        long strt = System.currentTimeMillis();
        JavaRDD<String> txtfile = javaspark.txtfile(args[0]);
        JavaRDD<String> sortcompleted = txtfile.sortBy(new Function<String, String>() {
            public String call(String line) throws Exception {
                return line.substring(0,101);
            }
        }, true, 16);
        String op = args[1];
        sortcompleted.saveAsTextFile(op);
        long duration = (System.currentTimeMillis() - strt)/1000;
		System.out.println("Time taken to sort " + elapsedTime);
    }

}