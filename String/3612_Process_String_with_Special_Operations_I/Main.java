class Solution {
    public String processStr(String s) {
        StringBuilder sb = new StringBuilder(s.length());
		
		for (char c : s.toCharArray()) {
			switch (c) {
				case '%':
					sb.reverse();
					break;
				case '*':
					if (sb.length() > 0) sb.deleteCharAt(sb.length() - 1);
					break;
				case '#':
					sb.append(sb.toString());
					break;
				default:
					sb.append(c);
					break;
			}
		}
		
		return sb.toString();
    }
}