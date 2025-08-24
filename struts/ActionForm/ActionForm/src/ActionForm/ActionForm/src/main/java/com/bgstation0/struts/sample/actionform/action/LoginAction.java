package com.bgstation0.struts.sample.actionform.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.struts.action.Action;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

import com.bgstation0.struts.sample.actionform.form.LoginForm;

public class LoginAction extends Action {
    @Override
    public ActionForward execute(ActionMapping mapping, ActionForm form,
            HttpServletRequest request, HttpServletResponse response) throws Exception {

        LoginForm loginForm = (LoginForm) form;
        String username = loginForm.getUsername();
        String password = loginForm.getPassword();

        if ("admin".equals(username) && "pass".equals(password)) {
            return mapping.findForward("success");
        } else {
            return mapping.findForward("error");
        }
    }
}
