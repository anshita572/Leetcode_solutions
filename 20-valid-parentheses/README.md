<h2><a href="https://leetcode.com/problems/valid-parentheses/">20. Valid Parentheses</a></h2><h3>Easy</h3><hr><div data-pf_style_display="block" data-pf_style_visibility="visible"><p data-pf_style_display="block" data-pf_style_visibility="visible">Given a string <code data-pf_style_display="inline" data-pf_style_visibility="visible">s</code> containing just the characters <code data-pf_style_display="inline" data-pf_style_visibility="visible">'('</code>, <code data-pf_style_display="inline" data-pf_style_visibility="visible">')'</code>, <code data-pf_style_display="inline" data-pf_style_visibility="visible">'{'</code>, <code data-pf_style_display="inline" data-pf_style_visibility="visible">'}'</code>, <code data-pf_style_display="inline" data-pf_style_visibility="visible">'['</code> and <code data-pf_style_display="inline" data-pf_style_visibility="visible">']'</code>, determine if the input string is valid.</p>

<p data-pf_style_display="block" data-pf_style_visibility="visible">An input string is valid if:</p>

<ol data-pf_style_display="block" data-pf_style_visibility="visible">
	<li data-pf_style_display="list-item" data-pf_style_visibility="visible">Open brackets must be closed by the same type of brackets.</li>
	<li data-pf_style_display="list-item" data-pf_style_visibility="visible">Open brackets must be closed in the correct order.</li>
</ol>

<p data-pf_style_display="block" data-pf_style_visibility="visible">&nbsp;</p>
<p data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Example 1:</strong></p>

<pre data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Input:</strong> s = "()"
<strong data-pf_style_display="inline" data-pf_style_visibility="visible">Output:</strong> true
</pre>

<p data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Example 2:</strong></p>

<pre data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Input:</strong> s = "()[]{}"
<strong data-pf_style_display="inline" data-pf_style_visibility="visible">Output:</strong> true
</pre>

<p data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Example 3:</strong></p>

<pre data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Input:</strong> s = "(]"
<strong data-pf_style_display="inline" data-pf_style_visibility="visible">Output:</strong> false
</pre>

<p data-pf_style_display="block" data-pf_style_visibility="visible">&nbsp;</p>
<p data-pf_style_display="block" data-pf_style_visibility="visible"><strong data-pf_style_display="inline" data-pf_style_visibility="visible">Constraints:</strong></p>

<ul data-pf_style_display="block" data-pf_style_visibility="visible">
	<li data-pf_style_display="list-item" data-pf_style_visibility="visible"><code data-pf_style_display="inline" data-pf_style_visibility="visible">1 &lt;= s.length &lt;= 10<sup data-pf_style_display="inline" data-pf_style_visibility="visible">4</sup></code></li>
	<li data-pf_style_display="list-item" data-pf_style_visibility="visible"><code data-pf_style_display="inline" data-pf_style_visibility="visible">s</code> consists of parentheses only <code data-pf_style_display="inline" data-pf_style_visibility="visible">'()[]{}'</code>.</li>
</ul>
</div>