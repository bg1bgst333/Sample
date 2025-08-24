<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<html>
<head><title>Login</title></head>
<body>
<h2>Login Form</h2>
<html:form action="/login">
    Username: <html:text property="username"/><br/>
    Password: <html:password property="password"/><br/>
    <html:submit value="Login"/>
</html:form>
</body>
</html>
