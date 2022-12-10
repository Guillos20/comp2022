class Sum {
    public static int operators(int n) {
      return n+1;
    }

    public static void main(String[] args) {
        operators(operators(operators(operators(operators(1)))));
        operators(1);
        operators(3);
        operators(operators(5));
      }
}
