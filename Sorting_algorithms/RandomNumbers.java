import java.util.Date;
import java.util.Random;

public class RandomNumbers
{
  private Random rnd;

  public RandomNumbers()
  {
    Date d = new Date();
    rnd = new Random(d.getTime());
  }

  public int getNextRandomNumber()
  {
    return rnd.nextInt(10000)+1;
  }
}