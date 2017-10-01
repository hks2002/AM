//Channge Default value, if mini default setting doesn't fit your require
/*-----------------------------------------------------------------------------*/
mini_debugger = false;
mini.DataTable.prototype.pageSize = 50;
mini.DataTable.prototype.autoLoad = false;
mini.Pager.prototype.sizeList = [50, 100, 500, 1000, 5000, 10000];
mini.ColumnModel.prototype._defaultColumnWidth = 150;
mini.DataGrid.prototype.showLoading = false;
mini.DataGrid.prototype.allowAlternating = true;
mini.DataGrid.prototype.showEmptytext = true;

var addedTabs = {};
//add dectect respose time to determine if open mask
/*
$(document).ajaxStart(function(){
                mini.mask({
                el: document.body,
                cls: 'mini-mask-loading'
            });
 });

$(document).ajaxStop(function(){
            mini.unmask(document.body);
 })
*/

$.ajaxSetup({
    complete: function(xhr,status){ 
　　　　if(status == 'timeout'){//timeout, other status is success,error etc.
 　　　　　 mini.showMessageBox({
                showModal: false,
                width: 250,
                title: mini.MessageBox.noteTitle,
                iconCls: "mini-messagebox-info",
                message: mini.AjaxMsgTimeOut,
                timeout: 2000
            });
　　　　}
     mini.parse();//parse each ajax feedback dom
　　},
    error : function (xhr, textStatus, errorThrown) {
        switch (xhr.status) {
        case 200:
             switch (textStatus) {
                 case "parsererror": // if control's request return login page.
                 var reg = /<script[^>]*>.*<\/script>/i;
                 if (reg.test(xhr.responseText)) {
                     $("#dynamicJS").html(xhr.responseText);
                 }else{
                     mini.showMessageBox({
                        showModal: false,
                        width: 250,
                        title: mini.MessageBox.noteTitle,
                        iconCls: "mini-messagebox-error",
                        message: xhr.responseText,
                        timeout: 2000
                    });
                 }
             }
             break;
        case 403:
            mini.showMessageBox({
                showModal: false,
                width: 250,
                title: mini.MessageBox.noteTitle,
                iconCls: "mini-messagebox-info",
                message: mini.AjaxMsg403,
                timeout: 2000
            });
            break;
        case 404:
            mini.showMessageBox({
                showModal: false,
                width: 250,
                title: mini.MessageBox.noteTitle,
                iconCls: "mini-messagebox-warning",
                message: mini.AjaxMsg404,
                timeout: 2000
            });
            break;
        case 500:
            mini.showMessageBox({
                showModal: false,
                width: 250,
                title: mini.MessageBox.noteTitle,
                iconCls: "mini-messagebox-error",
                message: mini.AjaxMsg500,
                timeout: 2000
            });
            break;
        default:
            mini.showMessageBox({
                showModal: false,
                width: 250,
                title: mini.MessageBox.noteTitle,
                iconCls: "mini-messagebox-error",
                message: mini.AjaxMsgDefault,
                timeout: 2000
            });
        }
    }
});

function styleSheetTag(url, id) {
    var head = document.getElementsByTagName("head")[0],

    linkTag = document.createElement("link");
    linkTag.id = id;
    linkTag.href = url;
    linkTag.rel = 'stylesheet';
    linkTag.type = 'text/css';
    head.appendChild(linkTag);
}

function onSkinChange(skin) {
    mini.Cookie.set('miniuiSkin', skin, 100);

    var cssTag = document.getElementById("miniuiSkin");
    if (cssTag) {
        if (skin.length < 1) {
            cssTag.href = "";
        } else {
            cssTag.href = "/css/" + skin + "/skin.css";
        }
    } else {
        styleSheetTag("/css/" + skin + "/skin.css", "miniuiSkin");
    }
}

function onModeChange(mode) {
    mini.Cookie.set('miniuiMode', mode, 100);

    var cssTag = document.getElementById("miniuiMode");
    if (cssTag) {
        if (mode.length < 1) {
            cssTag.href = "";
        } else {
            cssTag.href = "/css/default/" + mode + "-mode.css";
        }
    } else {
        styleSheetTag("/css/default/" + mode + "-mode.css", "miniuiMode");
    }
    mini.layout();
}

function onLangChange(lang) {
    mini.Cookie.set('lang', lang, 100);
    var jsTag = document.getElementById("miniuiLang");

    if (lang == "zh") {
        jsTag.src = "/js/zh_CN.js";
    } else {
        jsTag.src = "/js/en_US.js";
    }

    $.ajax({
        url: window.location.href,
        type: "post",
        dataType: "text",
        data: addedTabs,
        success: function (text) {
            var regDom = /<body[^>]*>([\s\S]*)<\/body>/;
            var regJs = /<script[^>]*>.*<\/script>/i;
            if (regDom.test(text)){
               document.body.innerHTML = text.match(regDom)[0];
            }else if (regJs.test(text)) {
               $("#dynamicJS").html(text);
            }
         }
    });
}

function onToDoRoleChange(toDoRole) {
    mini.Cookie.set('toDoRole', toDoRole, 100);
    mini.Cookie.set("mainTabsActiveIndex", 0, 100);
    mini.Cookie.set("subTabsActiveIndex", 0, 100);
    $.ajax({
        url: window.location.href,
        dataType: "text",
        success: function (text) {
            var regDom = /<body[^>]*>([\s\S]*)<\/body>/;
            var regJs = /<script[^>]*>.*<\/script>/i;
            if (regDom.test(text)){
               document.body.innerHTML = text.match(regDom)[0];
            }else if (regJs.test(text)) {
               $("#dynamicJS").html(text);
            }
        }
    });
}

function onMenuItemClick(e) {
    var tabs = mini.get("mainTabs");
    var tab = tabs.getTab(e.sender.name); //index or name(set it to url)
    if (!tab) {
        tab = {};
        tab.title = e.sender.text;
        tab.name = e.sender.name;
        tab.tooltip = e.sender.menuTooltip;
        tab.showCloseButton = true;
        tabs.addTab(tab);

        addedTabs[e.sender.name] = e.sender.menuNameAlt + '$$' +e.sender.menuTooltip;
    }
    tabs.activeTab(tab);
}

function onButtonClick(e) {
    var button = e.sender;
    $.ajax({
        url: button.name //name is url
    });
}

function onBeforeTabChange(e) {
    var tabs = mini.get(e.sender.id);

    var el = tabs.getTabBodyEl(e.tab);
    var ctls = mini.getChildControls(el);
    $(el).html("");
    for(var i=0,l=ctls.length;i<l;i++){
        ctls[i].destroy();
    }  
}

function onTabChange(e) {
    var tabs = mini.get(e.sender.id);
    if (tabs.id == "mainTabs") {
        mini.Cookie.set("mainTabsActiveIndex", tabs.activeIndex, 100);
    } else if (tabs.id == "subTabs") {
        mini.Cookie.set("subTabsActiveIndex", tabs.activeIndex, 100);
    } else {}

    if (e.tab) {
        var el = tabs.getTabBodyEl(e.tab);
        $.ajax({
            url: e.tab.name, //name is url            
            dataType: 'text',
            success: function (data) {
                if (data){
                    $(el).html(data);
                }
            }
        });
    }
}

function onTabClose(e) {
    var url = e.tab.name;
    delete addedTabs.url;
}

function doSearch(formId, gridId) {
    var grid = mini.get(gridId);
    var key = formSearchKey(formId);
    if (key.length > 0) {
        grid.load({
            key: key
        });
    } else {
        grid.load();
    }
}

function reloadGrid(gridId){
    var grid = mini.get(gridId);
    grid.reload();
}

function reloadGrids(grids){
    for(var i=0,l=grids.length;i<l;i++){
        //var name = grids[i].name.substring(4);
        //var searchForms = mini.getsByName("searchForm" + name);   //it's miniui's bug
        //doSearch(searchForms[i].id, grids[i].id);
        grids[i].load();
    }
}

function reloadControls(ctls){
    for(var i=0,l=ctls.length;i<l;i++){
        ctls[i].load(ctls[i].url);
    }
}

function saveForm(formId){
    var form     = new mini.Form("#" + formId);
    var formdata = form.getData();    
    var action   = $("#" + formId).attr("action");
    var name     = $("#" + formId).attr("name");

    $.ajax({
        url: action,
        type: "post",
        dataType:"json",
        data: formdata,
        success:function (data) {
            if (data){
                if (data.success){                    
                    mini.showTips({content: data.msg,state: "success", x: "center", y: "center"});                    
                    var grids = mini.getsByName("grid" + name.substring(4));
                    reloadGrids(grids);
                }else{
                    mini.alert(data.msg);
                }
            }
       }
   }); 
}

function resetForm(formId) {
    var form = new mini.Form("#" + formId);
    form.reset();
}

function clearForm(formId) {
    var form = new mini.Form("#" + formId);
    form.clear();
}

function readOnlyForm(formId){
    var form = new mini.Form("#" + formId);
    var controls=form.getFields();
      for(var i=0,l=controls.length;i<l;i++){
          controls[i].setReadOnly(true);
      }
}

function hideButton(divId){
    $("#" + divId).find("input:button").hide();
    $("#" + divId).find("a.mini-button").hide();  
}

function removeButton(divId){
    $("#" + divId).find("input:button").remove();
    $("#" + divId).find("a.mini-button").remove();  
}

function openWindow(winId){
    var win=mini.get(winId);
    win.show("center","middle");
}

function closeWindow(winId){
    var win = mini.get(winId);
    win.hide();
}

function stepWindow(winId){ 
    if ($(".mini-window").length>=2){
        var x = $(".mini-window").eq(-2).position().left;
        var y = $(".mini-window").eq(-2).position().top;

        $("#"+winId).css("left",(x+30)+"px");
        $("#"+winId).css("top",(y+30)+"px"); 
    }
}

function toggleSearch(ck, id) {
    var dom = document.getElementById(id);
    dom.className = !ck.checked ? "hideFieldset" : "";
    mini.layout();
}

function toggleAdvanceSearch(ck, formId) {
    var form = new mini.Form("#" + formId);
    var controls=form.getFields();
   
    for(var i=0,l=controls.length;i<l;i++){
        var controlName=controls[i].getName();
        if (controlName.substr(0,6)=='sqlOp_'){
            if (ck.checked) {
                controls[i].setVisible(true);
                controls[i].setValue('0');//sqlInvalid
            }else{
                controls[i].setVisible(false);
                controls[i].setValue('11');//sqlLike
            }            
        }
    }
}

function sqlOpChange(e){
    var listbox = e.sender;
    var controlName=listbox.getName();
    if (listbox.getValue() == 7  ||    //isNull
        listbox.getValue() == 8  ||    //isEmpty
        listbox.getValue() == 9  ||    //isNotNull
        listbox.getValue() == 10  )  //isNotEmpty
        {
          mini.getByName(controlName.substring(6)).setVisible(false);
          mini.getByName(controlName.substring(6)).setValue("");
          mini.getByName(controlName.substring(6)+'2').setVisible(false);
          mini.getByName(controlName.substring(6)+'2').setValue("");
    }else if(listbox.getValue() == 13  ||    //likeEscape
             listbox.getValue() == 14  ||    //notLikeEscape
             listbox.getValue() == 17  ||    //ilikeEscape
             listbox.getValue() == 18   )  //notILikeEscape
             {
               mini.getByName(controlName.substring(6)).setVisible(true);
               mini.getByName(controlName.substring(6)+'2').setVisible(true);
               mini.getByName(controlName.substring(6)+'2').setEmptyText(am.EscapeTextNote);
    }else if(listbox.getValue() == 21  ||     //between
             listbox.getValue() == 22   ) //notbetween
             {
               mini.getByName(controlName.substring(6)).setVisible(true);
               mini.getByName(controlName.substring(6)+'2').setVisible(true);
               mini.getByName(controlName.substring(6)+'2').setEmptyText(am.EmptyTextNote+'2');
    }else{
        mini.getByName(controlName.substring(6)).setVisible(true);
        mini.getByName(controlName.substring(6)+'2').setVisible(false);
        mini.getByName(controlName.substring(6)+'2').setValue("");
    }        
}

function formSearchKey(formId) {
    var key = '';
    var form = new mini.Form("#" + formId);
    var controls=form.getFields();
    var isAdvanceSearch=mini.getByName("advanceSearchCheckBox").getValue();
    
    for(var i=0,l=controls.length;i<l;i++){
        var controlName=controls[i].getName();
        if (controlName.substr(0,6)=='sqlOp_'){
            var op = controls[i].getValue();
            
            if (op == 7  ||    //isNull
                op == 8  ||    //isEmpty
                op == 9  ||    //isNotNull
                op == 10  )    //isNotEmpty
                {
                 key += '{"field":"' + controlName.substring(6) + '","op":"' + op + '"},';
            }else if(op == 13  ||    //likeEscape
                     op == 14  ||    //notLikeEscape
                     op == 17  ||    //ilikeEscape
                     op == 18  ||    //notILikeEscape
                     op == 21  ||    //between
                     op == 22   )    //notbetween
                     {
                      var vals1 = mini.getByName(controlName.substring(6),form).getValue().trim();
                      var vals2 = mini.getByName(controlName.substring(6)+'2',formId).getValue().trim();
                      
                       key += '{"field":"' + controlName.substring(6) + '","op":"' + op 
                           + '","vals":"' + vals1 + ' '+vals2+'"},';
            }else if (op > 0){
                var vals = mini.getByName(controlName.substring(6),form).getValue().trim();
                if (isAdvanceSearch=="true"){
                    key += '{"field":"' + controlName.substring(6) + '","op":"'+op+'","vals":"'+vals+'"},'
                }else{
                    if (vals!=""){
                        if (vals.indexOf("%")!='-1'){
                            key += '{"field":"' + controlName.substring(6) + '","op":"11","vals":"'+vals+'"},';
                        }else{
                            key += '{"field":"' + controlName.substring(6) + '","op":"11","vals":"'+vals+'%"},';
                        }                        
                    }
                }
            }               
        }
    }
    if (key.length > 0) {
        key = key.slice(0, -1);
        key = '[' + key + ']';
    }
    return key;
}

function selectOnlyOne(items){
    if (items.length <= 0) {
        mini.alert(am.PleaseSelcetOneRecord);
        return false;
    } else if (items.length > 1) {
        mini.alert(am.PleaseSelcetOnlyOneRecord);
        return false;
    }
    return true;
}

function selectAtleastOne(items){
     if (items.length <= 0) {
        mini.alert(am.PleaseSelcetAtLeastOneRecord);
        return false;
    } 
    return true;
}

function createRecord(title,width,height,url){
    var win = mini.open({
        title: am.Create + " - " + title,
        showModal: false,showMaxButton:true,showCollapseButton:true,allowResize:true,allowDrag:true,showFooter:true,
        footerStyle:"text-align:left; padding:2px;",
        width: width,
        height: height
    });
    stepWindow(win.id);

 $.ajax({
        url: url + "?action=create",
        type: "get",
        dataType:"text",
        success: function (text) {
            if (text){
                $(win.getBodyEl()).html(text);
                var formId = win.getBodyEl().getElementsByClassName("form")[0].id;
                var footer ='<a class="mini-button" onclick="saveForm(\''+formId+'\')">' + am.Save + '</a>';
                    footer +=' ';
                    footer +='<a class="mini-button" onclick="closeWindow(\''+win.id+'\')">' + am.Close + '</a>';
                win.setFooter(footer);   
            }
        }
    });  
}

function editRecord(id,title,width,height,url,pks){
    var control = mini.get(id);
    var items = control.getSelecteds();
    
    if (!selectOnlyOne(items)){
        return;
    }
    var win = mini.open({
    title: am.Edit + " - " + title,
    showModal: false,showMaxButton:true,showCollapseButton:true,allowResize:true,allowDrag:true,showFooter:true,
    footerStyle:"text-align:left; padding:2px;",
    width: width,
    height: height
   });
   stepWindow(win.id);
   
   var pkstr='';
   for(i = 0,len=pks.length; i < len; i++) {
      pkstr += "&" + pks[i] + "=" + items[0][pks[i]];
   }

    $.ajax({
        url: url + pkstr,
        type: "get",
        dataType:"text",
        success: function (text) {
            if (text){
                $(win.getBodyEl()).html(text);
                var formId = win.getBodyEl().getElementsByClassName("form")[0].id;
                var footer ='<a class="mini-button" onclick="saveForm(\''+formId+'\')">' + am.Save + '</a>';
                    footer +=' ';
                    footer +='<a class="mini-button" onclick="closeWindow(\''+win.id+'\')">' + am.Close + '</a>';
                win.setFooter(footer); 
            }
        }
    });
}

function showRecord(id,title,width,height,url,pks){
    var control = mini.get(id);
    var items = control.getSelecteds();
    
    if (!selectOnlyOne(items)){
       return ;    
    }
    var win = mini.open({
    title: am.Show + " - " + title,
    showModal: false,showMaxButton:true,showCollapseButton:true,allowResize:true,allowDrag:true,showFooter:true,
    footerStyle:"text-align:left; padding:2px;",
    width: width,
    height: height
   });
   stepWindow(win.id);
   
   var pkstr='';
   for(i = 0,len=pks.length; i < len; i++) {
      pkstr += "&" + pks[i] + "=" + items[0][pks[i]];
   }

    $.ajax({
        url: url + pkstr,
        type: "get",
        dataType:"text",
        success: function (text) {
            if (text){
               $(win.getBodyEl()).html(text);
                var formId = win.getBodyEl().getElementsByClassName("form")[0].id;
                var footer ='<a class="mini-button" onclick="closeWindow(\''+win.id+'\')">' + am.Close + '</a>';
                win.setFooter(footer); 
            }                
        }
    });   
}

function deleteRecord(id,url,pks,token){
    var control = mini.get(id);
    var items = control.getSelecteds();
    var key = [];
    
    if (!selectAtleastOne(items)){
        return;     
    }
    for (var i = 0; i < items.length; ++i) {
        var obj = {};
        for(k = 0,len=pks.length; k < len; k++) {
            obj[pks[k]]=items[i][pks[k]];
        }     
       key.push(obj);            
    }
    $.ajax({
            url: url,
            type: "post",
            dataType:"json",
            data: {
                authenticity_token: token,
                key: mini.encode(key)
            },
            success: function (data) {
                if (data){
                        if (data.success) {
                        mini.showTips({content: data.msg,state: "success", x: "center", y: "center", timeout: 2000});
                             if (control.type == "datagrid"){
                                control.removeRows(items);
                             }else if(control.type == "tree"){
                                control.removeNodes(items);
                             }else if(control.type == "listbox"){
                                control.removeItems(items);
                             } 
                           
                    } else {
                        mini.alert(data.msg);
                    }
                }
            }
        });       
}

function relationRecord(id,url,pks,vals,token){
  var control = mini.get(id);
  var items = control.getSelecteds();
  var key = [];

  if (!selectAtleastOne(items)){
     return;
  }
  
  for (var i = 0; i < items.length; ++i) {
      var obj = {};
      for(k = 0,len=pks.length; k < len; k++) {//is array
                obj[pks[k]]=items[i][pks[k]];
      }
      for (var k in vals){//is object
                obj[k]=vals[k];
      }
      key.push(obj);
  }

  $.ajax({
      url: url,
      type: "post",
      dataType: "json",
      data: {
          authenticity_token: token,
          key: mini.encode(key)
      },
      success: function (data) {
            if (data){
              if (data.success) {
                  mini.showTips({content: data.msg,state: "success", x: "center", y: "center", timeout: 2000});
                  var ctls = mini.getsByName(control.name);
                  reloadControls(ctls);    
              } else {
                  mini.alert(data.msg);
              }
           }
      }
  }); 
}

function relationWindow(obj,title,width,height,dataUrl,actionUrl,pks,vals,token){
      var win = mini.open({
            title: am.Assign + " - " + title,
            showModal: true,allowResize:true,allowDrag:true,showFooter:true,
            footerStyle:"text-align:left; padding:2px;",
            width: width,
            height: height
        });
     
    // win.show(obj,{xAlign:"left",yAlign:"Above"});
     
     var pkstr='';
     for (var i in vals){//vals is object
           pkstr += "&" + i + "=" + vals[i];
     }
    $.ajax({
        url: dataUrl+ pkstr,
        type: "get",
        dataType:"text",
        success:function(text){
            if (text){            
                $(win.getBodyEl()).html(text);
                var controlId = win.getBodyEl().getElementsByClassName("mini-datagrid")[0].id;
                var footer ='<a class="mini-button" onclick="relationRecord(\''+controlId+'\',\''+actionUrl+'\','+mini.encode(pks).replace(/\"/g, "'")+','+mini.encode(vals).replace(/\"/g, "'")+',\''+token+'\')">'+am.Assign+'</a>';
                    footer +=' ';
                    footer +='<a class="mini-button" onclick="closeWindow(\''+win.id+'\')">'+am.Close+'</a>';
                win.setFooter(footer);            
            }
          }
    });
}

function moveUp(id,url,pks,token) {
  var control = mini.get(id);
  var items = control.getSelecteds();
  
  if (selectAtleastOne(items)){
        for (var i = 0; i < items.length; ++i) {
            var obj = {};
            for(k = 0,len=pks.length; k < len; k++) {
                obj[pks[k]]=items[i][pks[k]];
            }     
           key.push(obj);            
        }

           $.ajax({
              url: url,
              type: "post",
              dataType: "json",
              data: {
                  authenticity_token: token,
                  key: mini.encode(key)
              },
              success: function (data) {
                  if (data){
                      if (data.success) {
                            for (var i = 0, l = items.length; i < l; i++) {
                                  var item = items[i];
                                  var index = control.indexOf(item);
                                  if (control.type == "datagrid"){
                                     control.moveRow(item, index - 1);
                                  }else if(control.type == "tree"){
                                     control.moveNode(item, index - 1);
                                  }else if(control.type == "listbox"){
                                     control.moveItem(item, index - 1);
                                  }
                            }
                        mini.showTips({content: data.msg,state: "success",x: "center", y: "center",timeout: 2000});
                      } else {
                          mini.alert(data.msg);
                      }
                    }
              }
            });
    }
}

function moveDown(id,url,pks,token) {
  var control = mini.get(id);
  var items = control.getSelecteds();
  
  if (selectAtleastOne(items)){
        for (var i = 0; i < items.length; ++i) {
            var obj = {};
            for(k = 0,len=pks.length; k < len; k++) {
                obj[pks[k]]=items[i][pks[k]];
            }     
           key.push(obj);            
        }

           $.ajax({
              url: url,
              type: "post",
              dataType: "json",
              data: {
                  authenticity_token: token,
                  key: mini.encode(key)
              },
              success: function (data) {
                  if (data){
                      if (data.success) {
                            for (var i = items.length - 1; i >= 0; i--) {
                                  var item = items[i];
                                  var index = control.indexOf(item);
                                  if (control.type == "datagrid"){
                                     control.moveRow(item, index + 1);
                                  }else if(control.type == "tree"){
                                     control.moveNode(item, index + 1);
                                  }else if(control.type == "listbox"){
                                     control.moveItem(item, index + 1);
                                  }
                              }
                        mini.showTips({content: data.msg,state: "success",x: "center", y: "center",timeout: 2000});
                      } else {
                          mini.alert(data.msg);
                      }
                    }
              }
            });
    }
}

function refreshPage()
{
  var grids= mini.findControls(function(control){
       if(control.type == "datagrid") {
           return true;
       }
  });
  var trees= mini.findControls(function(control){
       if(control.type == "tree") {
           return true;
       }
  });
  var listboxs= mini.findControls(function(control){
       if(control.type == "listbox") {
           return true;
       }
  });
   reloadGrids(grids);
   reloadControls(trees);
   reloadControls(listboxs);  
}

var refreshInterval=setInterval("refreshPage()",1800000);