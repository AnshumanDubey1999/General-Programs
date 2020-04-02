import java.io.*;


public class nptel6 {
    static Reader sc;
    static Printer out;
    static int distributions[], distributionIndexes[];
    static long totalSum;

    public static void main(String[] args) throws IOException {
        sc = new Reader();
        out = new Printer();
        int testCases, m, k, b[];
        long sum;
        double optimalValue;
        testCases = 1;
        while (testCases-- > 0) {
            m = sc.nextInt();
            k = sc.nextInt();
            b = new int[m];
            distributions = new int[k];
            distributionIndexes = new int[k];
            sum = 0l;
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
                sum += b[i];
            }
            totalSum = sum;
            optimalValue = 1.0*sum/k;
            for (int i = 0, j = 0; i < k && j<m;i++) {
                //System.out.println(i+" "+optimalValue+" "+sum);
                for (; j < m; j++) {
                    if((distributions[i] + b[j])>optimalValue && i!=k-1)
                        break;
                    distributions[i]+=b[j];
                    //PRINT.ArrayHorizontally(distributions);
                }
                distributionIndexes[i] = j;
                sum -=distributions[i];
                optimalValue = 1.0*sum/(k-i-1);
            }
            PRINT.ArrayHorizontally(distributions);
            PRINT.ArrayHorizontally(distributionIndexes);
            findOptimumCombination(b, k, 0);
            for (int i = 0, j = 0; i < m; i++) {
                out.print(b[i]);
                if(i==(m-1))
                    out.print("\n");
                else if(j<(k - 1)&& (i+1)==distributionIndexes[j]){
                    out.print(" / ");
                    j++;
                }
                else
                    out.print(" ");
            }
        }

        out.close();
    }

    private static void findOptimumCombination(int[] b, int k, int number) {
        System.out.println("Recursion: "+number);
        int currentMax = maxIndex(), m1 = Integer.MAX_VALUE, m2 = Integer.MAX_VALUE;
        //LeftSide
        if(currentMax>0 && (distributions[currentMax-1]+b[distributionIndexes[currentMax-1]])<distributions[currentMax])
            m1 = distributions[currentMax-1]+b[distributionIndexes[currentMax-1]];
        //RightSide
        if(currentMax<(k-1) && (distributions[currentMax+1]+b[distributionIndexes[currentMax]-1])<distributions[currentMax])
            m2 = distributions[currentMax+1]+b[distributionIndexes[currentMax]-1];
        if(m1==m2 && m2==Integer.MAX_VALUE)
            return;
        else if(m1<=m2){
            distributions[currentMax-1] += b[distributionIndexes[currentMax-1]];
            distributions[currentMax] -= b[distributionIndexes[currentMax-1]+1];
            distributionIndexes[currentMax-1]++;
        }
        else{
            distributions[currentMax+1] += b[distributionIndexes[currentMax]-1];
            distributions[currentMax] -= b[distributionIndexes[currentMax]-1];
            distributionIndexes[currentMax]--;
        }
        PRINT.ArrayHorizontally(distributions);
        PRINT.ArrayHorizontally(distributionIndexes);
        findOptimumCombination(b, k, number+1);
    }

    private static int maxIndex() {
        int max = distributions[0], maxIndex = 0;
        for (int i = 1; i < distributions.length; i++) {
            if(distributions[i]>max){
                max = distributions[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }


    static class Printer {
        private OutputStream outputStream;

        public Printer() {
            outputStream = new BufferedOutputStream(System.out);
        }

        public Printer(String file_name) {
            try {
                outputStream = new BufferedOutputStream(new FileOutputStream(file_name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public void print(Object object) throws IOException {
            outputStream.write(String.valueOf(object).getBytes());
        }

        public void println() throws IOException {
            outputStream.write(("\n").getBytes());
        }

        public void println(Object object) throws IOException {
            outputStream.write((object + "\n").getBytes());
        }

        public void close() throws IOException {
            outputStream.flush();
        }
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}