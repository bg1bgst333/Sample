package com.bgstation0.struts.sample.actionmessages;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.struts.action.*;

public class MessageAction extends Action {
    @Override
    public ActionForward execute(ActionMapping mapping, ActionForm form,
                                 HttpServletRequest request, HttpServletResponse response) throws Exception {

        // メッセージオブジェクト
        ActionMessages messages = new ActionMessages();
        messages.add(ActionMessages.GLOBAL_MESSAGE, new ActionMessage("message.hello"));

        // リクエストにメッセージを保存
        saveMessages(request, messages);
        
        return mapping.findForward("success");
    }
}
