# Rational_Library
Rational Library Static header for C++.

<p>The library allows to use rational numbers in your project. The number does not reduce itself to simplest form automatically.
It has to be simplified when and where required using the inbuilt function.</p>

<p>The rational class uses intmax_t as the base data type for storing numerator and denominator.</p>

<h2>Constructor</h2>
<p>The constructor can be called using any of the fundamental integer types as numerator or denominator.</p>
<h3>Examples</h3>
<ul>
  <li><code>rational r; // Constructs with value of 1/1</code></li>
  <li><code>rational r(3,4); // Constructs with value of 3/4</code></li>
  <li><code>rational r(3); // Constructs with value of 3/1</code></li>
  <li><code>rational r('a',3); // Constructs with value of 97/3 (ASCII value of 'a' is 97)</code></li>
</ul>

<h2>Operators</h2>
<p>The class supports arithmatic and relational operators.</p>
<ul>
  <li>Shorthand Assignment Operators <code>+=, -=, *=, /=</code></li>
  <li>Arithmatic Operators <code>+, -, *, /</code></li>
  <li>Relational Operators <code><, <=, >, >=, ==, !=</code></li>
</ul>
<p>The operands can be both rational or fundamental integer types.</p>

<h2>I/O Operators</h2>
<p>The input and output stream operators are also overloaded for ease of use.</p>
<h3>Examples</h3>
<ul>
  <li><code>cin >> a >> b; // a and b are two rational objects</code></li>
  <li><code>cout << a << b; // a and b are two rational objects</code></li>
</ul>
<p>The intput format is x/y (3/4), if the denominator is not specified it is assumed to be 1.</p>
<p>The output format is also similar x/y (3/4).</p>

<h2>Other Member Function</h2>
<p>Other member functions of the class.</p>
<ul>
  <li>GCD function <code>int gcd = r.GCD(); // Returns the GCD of the number</code></li>
  <li>Simplify function for normalizing <code>r.simplify(); // 6/8 is simplified to 3/4</code></li>
</ul>

<h2>Other Utility functions</h2>
<p>Other functions defined as utility for the class.</p>
<ul>
  <li>abs for absolute <code>a = abs(b); // -3/4 returns 3/4</code></li>
</ul>

<h2>References</h2>
<ul>
  <li>http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3363.html</li>
  <li>http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3611.html</li>
</ul>
