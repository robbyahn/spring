<?php

/**
 * Task view callback.
 */
function task_view($task) {
  drupal_set_title(entity_label('task', $task));
  return entity_view('task', array(entity_id('task', $task) => $task), 'full');
}

function task_user_overview($user) {
  $output = '';

  if (entity_access('create', 'task', 'task')) {
    // Get quick create form.
    $form = drupal_get_form('task_quick_create_task_form');
    $output .= render($form);
  }

  $user_task_page = arg(3);

  switch ($user_task_page) {
    case "assigned":
      $view_display = 'user_assigned_tasks';
      break;
    case "completed":
      $view_display = 'user_completed_tasks';
      break;
    default:
      $view_display = 'user_tasks';
  }

  // Load view.
  $output .= views_embed_view('task_user_tasks', $view_display);
    
  /* Display course enrolled */
  //dsm($user);  
  //$user->uid
  
  $type = "enroll"; 
  $enroll_nodes = node_load_multiple(array(), array('type' => $type)); 
  //dsm($enroll_nodes);
  
  //dsm($user->uid);
  $my_course = array();
  
  foreach ($enroll_nodes as $enroll_node):      
      //dsm($enroll_node->uid);
      if($user->uid == $enroll_node->uid) {
        $enroll_courses = $enroll_node->field_courses;
        foreach ($enroll_courses as $enroll_course):      
             //dsm($enroll_course);
             foreach ($enroll_course as $enroll_course_tid):      
                 //dsm($enroll_course_tid['target_id']);  //finally get entity id
                 $my_course[] = $enroll_course_tid['target_id'];
                 //dsm($course_nodes);
             endforeach;
        endforeach;
      }
  endforeach;
  
  //dsm($my_course);
  $course_nodes = node_load_multiple($my_course, array('type' => "course")); 
  
  //dsm($course_nodes);
  foreach ($course_nodes as $course_nodes_title):      
    // dsm($course_nodes_title->title);
    //$output .= $course_nodes_title->title.'<br/>';
    $task = entity_create('task', array('type' => 'task'));
    $task->title = $course_nodes_title->title;
    
    //dsm(task_list_load(3));
    //task_save($task);    
  endforeach;
  
  $output .= '<hr/>';
  

  return $output;
}
