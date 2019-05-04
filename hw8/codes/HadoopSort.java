import java.io.IOException;
import java.util.*;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;

public class HadoopSort 
{

    public static class TaskMapper extends Mapper<Object, Text, Text, Text>
	{

        public Text tk1 = new Text();
        public Text tk2 = new Text();
        public void map(Object key, Text value, Context context)  
		{
            String meaning= value.toString();
            tk2.set(meaning.substring(10));
            tk1.set(meaning.substring(0, 10));
            context.write(tk1, tk2);
        }
    }
	
	public static class StringReducer extends Reducer<Text,Text,Text,Text> 
	{
        Text vals=new Text();
        public void reduce(Text MapKey, Iterator<Text>  MapVal, Context ctx)  
		{
            while(MapVal.hasNext())
                vals.set(MapVal.next());
            ctx.write(MapKey,vals);
        }
    }

    public static void main(String[] args) 
	{
        Configuration set1 = new Configuration();
        long strt = System.currentTimeMillis();
        Job wk = Job.getInstance(set1, "Distributed Hadoop Sort");
        wk.setJarByClass(HadoopSort.class);
        wk.setMapperClass(TaskMapper.class);
        wk.setReducerClass(StringReducer.class);
        wk.setOutputKeyClass(Text.class);
        wk.setOutputValueClass(Text.class);
        FileInputFormat.addInputPath(wk, new Path(args[0]));
        FileOutputFormat.setOutputPath(wk, new Path(args[1]));
        double elapsedTime = (System.currentTimeMillis()-strt)/1000.0;
        System.out.println("Time taken to sort " + elapsedTime);
        System.exit(wk.waitForCompletion(true) ? 0 : 1);
    }
}