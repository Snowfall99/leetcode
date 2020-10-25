object Solution {
    def hammingDistance(x: Int, y: Int): Int = {
        var count = 0
        val z = (x ^ y).toBinaryString
        for (i<-0 until z.length) {
            if (z(i) == '1')
                count += 1
        }
        count
    }
}