<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<html>
<head><title>ActionMessage</title></head>
<body>
<h2>ActionMessage</h2>

<html:messages id="msg" message="true">
    <li><bean:write name="msg" /></li>
</html:messages>

</body>
</html>