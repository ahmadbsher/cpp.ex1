בפרויקט זה, מחלקת גרף ממומשת תוך שימוש בסדרת אלגוריתמים להפעלת גרפים ובהצגת מטריצת שכנות. הגרף תומך בקשתות עם משקל ויכול להיות מכוון או לא מכוון.

קבצים
Graph.hpp: קובץ כותרת המגדיר את מחלקת גרף.
Graph.cpp: כל השיטות של מחלקת גרף ממומשות בקובץ זה.
Algorithms.hpp: קובץ כותרת המגדיר את מחלקת האלגוריתמים.
Algorithms.cpp: מימוש שיטות מחלקת האלגוריתמים.
Demo.cpp: תוכנית הדגמה שמראה איך להשתמש במחלקות גרף ואלגוריתמים.

מחלקת גרף
Graph.hpp
מחלקת הגרף מוגדרת בקובץ Graph.hpp. היא כוללת:

loadGraph(const std::vector<std::vector<int>>& matrix): שיטה לטעינת מטריצת השכנות לתוך הגרף.
printGraph() const: שיטה להדפסת מטריצת השכנות של הגרף.

מחלקת אלגוריתמים
Algorithms.hpp
קובץ Algorithms.hpp מגדיר את מחלקת האלגוריתמים עם מספר שיטות סטטיות להפעלת הגרף:

isConnected(const Graph& g): בודק אם הגרף מחובר.
shortestPath(const Graph& g, int start, int end): מוצא את המסלול הקצר ביותר בין שני קודקודים.
isContainsCycle(const Graph& g): בודק אם הגרף מכיל מעגל.
isBipartite(const Graph& g): בודק אם הגרף דו צדדי.
negativeCycle(const Graph& g): מוצא מעגל שלילי בגרף.