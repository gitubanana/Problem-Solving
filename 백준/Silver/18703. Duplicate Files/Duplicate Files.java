import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class DuplicatedFiles {
    private Map<String, Integer> fileIds = new HashMap<>();

    public void add(String name, int newId) {
        Integer originId = fileIds.get(name);
        if (originId != null && originId < newId) {
            return;
        }

        fileIds.put(name, newId);
    }

    public List<String> toSortedStrings() {
        return fileIds.values().stream()
            .sorted()
            .map(String::valueOf)
            .collect(Collectors.toList());
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            int fileCnt = Integer.parseInt(br.readLine());
            DuplicatedFiles duplicatedFiles = new DuplicatedFiles();

            while (fileCnt-- > 0) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                duplicatedFiles.add(st.nextToken(), Integer.parseInt(st.nextToken()));
            }

            bw.append(String.join(" ", duplicatedFiles.toSortedStrings()));
            bw.append("\n");
        }

        bw.flush();
    }
}