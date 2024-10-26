import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static class Student implements Comparable<Student> {
        String name;
        int likeCnt;

        Student(String name, int likeCnt) {
            this.name = name;
            this.likeCnt = likeCnt;
        }

        @Override
        public int compareTo(Student o) {
            if (this.likeCnt != o.likeCnt) {
                return this.likeCnt - o.likeCnt;
            }

            return o.name.compareTo(this.name);
        }
    }

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        HashMap<String, Integer> popularity = new HashMap<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < size; i++) {
            popularity.put(st.nextToken(), 0);
        }

        while (size-- > 0) {
            st = new StringTokenizer(br.readLine());

            while (st.hasMoreTokens()) {
                String like = st.nextToken();

                popularity.put(like, popularity.get(like) + 1);
            }
        }

        ArrayList<Student> students = new ArrayList<>(popularity.size());
        for (Map.Entry<String, Integer> set : popularity.entrySet()) {
            students.add(new Student(set.getKey(), set.getValue()));
        }

        students.sort(Comparator.reverseOrder());
        for (Student student : students) {
            bw.append(student.name+" "+student.likeCnt+"\n");
        }
        bw.flush();
    }
}